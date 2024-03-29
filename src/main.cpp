#include <Arduino.h>

// Declare the debugging level then include the header file.
// Choose DEBUGLEVEL_NONE if you don't want to show anything in console
#define DEBUGLEVEL DEBUGLEVEL_DEBUGGING
// #define DEBUGLEVEL DEBUGLEVEL_NONE
#include "debug.h"
// Serial Plot data. Comment if you don't want to use it
#define PLOTTER

// Declare what message you want to display on the console.
// User picks console message from this list
// This selection will not be effective if DEBUGLEVEL is DEBUGLEVEL_NONE
#define DISTANCE
#define LEVEL
#define VOLUMEN

// Librerias Globales
#include <LiquidCrystal.h>
// LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
#include "filtro.h"

//-------------lcd---------
char data1[] = "ALT";
char data2[] = "ERROR";
byte char_x = 0;
byte char_y = 0;
int ledback = 12;

//---------Variables del tanque---------
#define DIST_TOPE 104        // maximum level, measured with the tank empty in cm
const int NIVEL_BAJO = 20;   // low level percentage from which I give a low level alarm
const int NIVEL_ALTO = 100;  // high percentage level from which I give a full tank alarm
const float ancho = 195.5;   // cm
const float largo = 200.0;   // cm
const float tabiqueA = 14.5; // partition width cm
const float tabiqueL = 200;  // septum length cm
float columnaLiquida;
float VolumenDinamicoTabique;
float litros;
const int sameReadings = 10;     // number of consecutive readings to consider it valid. Avoid sounding alarm with bad readings
int low_read = 0;                // counter reading of low level
int full_read = 0;               // counter reading of full level
float lastDistance = 0.0;        // Variable to store the last valid sensor reading
int randomReadingsThreshold = 2;  //Threshold to detect random reads

//JSN-SR04 sensor. Detection range: 25cm -450cm
int deadZone = 25;  //Dead zone in cm, which the sensor does not read well

//-------------filter variables--------
float averagedistance = 0;

//------------- Button---------
#define keyPin 3 // button is connected to pin 3(INT 1)

// Button debouncing
const uint8_t DEBOUNCE_DELAY = 10; // in milliseconds

struct Button
{
  // state variables
  uint8_t pin;
  bool lastReading;
  uint32_t lastDebounceTime;
  uint16_t state;

  // methods determining the logical state of the button
  bool pressed() { return state == 1; }
  bool released() { return state == 0xffff; }
  bool held(uint16_t count = 0) { return state > 1 + count && state < 0xffff; }

  // method for reading the physical state of the button
  void read()
  {
    // reads the voltage on the pin connected to the button
    bool reading = digitalRead(pin);

    // if the logic level has changed since the last reading,
    // we reset the timer which counts down the necessary time
    // beyond which we can consider that the bouncing effect
    // has passed.
    if (reading != lastReading)
    {
      lastDebounceTime = millis();
    }

    // from the moment we're out of the bouncing phase
    // the actual status of the button can be determined
    if (millis() - lastDebounceTime > DEBOUNCE_DELAY)
    {
      // don't forget that the read pin is pulled-up
      bool pressed = reading == LOW;
      if (pressed)
      {
        if (state < 0xfffe)
          state++;
        else if (state == 0xfffe)
          state = 2;
      }
      else if (state)
      {
        state = state == 0xffff ? 0 : 0xffff;
      }
    }

    // finally, each new reading is saved
    lastReading = reading;
  }
};
// Creating the button object with {pin, lastReading, lastDebounceTime, state}
Button button = {keyPin, HIGH, 0, 0};

// Ultrasonic data
bool sensorFail = false;
int nivel = 0; // level in %
bool lvlfull = true;
bool lowlvl = true;
long duration = 0;
int distance = 0;
#define trigPin 2
#define echoPin 5

struct Sensor
{
  // state variables
  uint8_t trigger;
  uint8_t echo;

  // methods for sensor isValidReading, isRandomReading, get_dist, get_level and get volume
  bool isValidReading(float currentdistance) 
  {
    return (currentdistance >= deadZone && currentdistance <= DIST_TOPE) ? true : false; // Rules out sensor errors, discards bad readings.
  }

  bool isRandomReading(float currentDistance)
  {
  //Check difference between the current reading and the last reading or current reading is greater than DIST_TOPE
      return (abs(currentDistance - lastDistance) > randomReadingsThreshold) || currentDistance > DIST_TOPE ? true : false;
  }

  float get_dist()
  {
    // Clears the trigPin
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigger, HIGH);
    delayMicroseconds(20);
    digitalWrite(trigger, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echo, HIGH, 26000); // timeout de 200000 microsegundos que es 26ms

    // Calculating the distance distance= duration/58;
    float distance = (float)(duration / 58);

    #ifdef DISTANCE
    debuglnD("Distancia en tiempo real: " + String(distance));
    #endif

    return distance;
  }

  int get_level()
  {
    float currentDistance = get_dist();

    if (isValidReading(currentDistance)) // Rules out sensor errors, discards bad readings.
    {
      averagedistance = movingAverage(currentDistance); // final value using moving average
      sensorFail = false;                        // Reset to false if a valid reading is obtained
      lastDistance = currentDistance;

    #ifdef DISTANCE
      debuglnD("Distancia average: " + String(averagedistance));
    #endif

      columnaLiquida = DIST_TOPE - averagedistance;
      nivel = map(columnaLiquida, 0, DIST_TOPE - deadZone, 0, 100); // 79 cm would be the maximum level in % for sensor safety (25cm)

    #ifdef LEVEL
      debuglnD("Nivel en porciento: " + String(nivel));
    #endif
    }
    else 
    {
      if (isRandomReading(currentDistance)) { //The reading is considered random, perform the necessary actions
      sensorFail = true; // Trigger sensorFail if reading is incorrect or out of range
      }
    }

    nivel = (nivel < 0) ? 0 : (nivel > 100) ? 100 : nivel;
    return nivel;
  }

  float get_volume()
  {
    VolumenDinamicoTabique = (tabiqueA * tabiqueL * columnaLiquida); // calculation of the volume of the partition up to the height of the water

  #ifdef VOLUMEN
    debuglnD("Volumen del tabique a una altura de " + String(columnaLiquida) + " cm es de " + String(VolumenDinamicoTabique) + " cm^3.");
  #endif

    float volumenRealTanque = (ancho * largo * columnaLiquida) - VolumenDinamicoTabique;

  #ifdef VOLUMEN
    debuglnD("Volumen de agua: " + String(volumenRealTanque) + " cm^3.");
  #endif

    litros = volumenRealTanque / 1000.0;

    return litros;
  }
};

Sensor ultraSonic = {trigPin, echoPin}; // Creating the ultraSonic object with {trigPin, echoPin}

// Draw library
#include "Tank.h"
Tank *draw = new Tank(&lcd); // Creating the draw object with {lcd}
#include "draw.h"

struct Draw
{
  // state variables
  int level;
  // methods for draw a tank
  void levels() { 
  switch (nivel) { 
    case 1 ... 5: 
      empty(); 
      break; 
    case 6 ... 10: 
      ten(); 
      break; 
    case 11 ... 20: 
      twenty(); 
      break; 
    case 21 ... 30: 
      thirty(); 
      break; 
    case 31 ... 40: 
      forty(); 
      break; 
    case 41 ... 50: 
      fifty(); 
      break; 
    case 51 ... 60: 
      sixty(); 
      break; 
    case 61 ... 70: 
      seventy(); 
      break; 
    case 71 ... 80: 
      eighty(); 
      break; 
    case 81 ... 90: 
      ninety(); 
      break; 
    default: 
      full(); 
      break; 
  } 
} 
};

Draw tank = {nivel}; // Creating the object draw tank with {level}

//-------------tiempo en pantalla---------
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long sleep_time = 60000; // Time in sec to turn off the backlight 1mint
bool ledbacklight;

//-------------Buzzer---------
#define BUZZER_PIN 4 // Buzzer BUZZER_PIN
// Otras librerias
#include "font.h"
#include "buzzer.h"
#include "alarms.h"

void setup()
{
  Serial.begin(9600);
  startMillis = millis(); // initial start time

  // Activamos la LCD
  lcd.begin(20, 4);
  lcd.clear();

  // Inicializamos los pines
  pinMode(BUZZER_PIN, OUTPUT); // buzzer output
  pinMode(keyPin, INPUT);      // boton
  pinMode(ledback, OUTPUT);    // backlight
  pinMode(trigPin, OUTPUT);    // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);     // Sets the echoPin as an Input

  // Turn on Backlight
  digitalWrite(ledback, HIGH);

  // Print the LOGO
  createChars();
  printBigCharacters(data1, 5, 0);
  lcd.setCursor(1, 2);
  lcd.print("Another Level Tank");
  lcd.setCursor(4, 3);
  lcd.print("..Loading..");
  lcd.display();
  delay(1000);
  buzzer_intro();
  delay(1000);
  lcd.clear();
}

void loop()
{
  button.read();

  // Get the level distance and volume
  nivel = ultraSonic.get_level();
  litros = ultraSonic.get_volume();
  distance = ultraSonic.get_dist();

// DEBUG for Serial Plotter https://github.com/CieNTi/serial_port_plotter
  #ifdef PLOTTER
  Serial.print("$");
  Serial.print(distance);
  Serial.print(" ");
  Serial.print(averagedistance);
  Serial.print(" ");
  Serial.print(nivel);
  Serial.print(";");
  #endif

  // Alarms
  if (nivel <= NIVEL_BAJO)
  {
    low_read++;
    if (low_read >= sameReadings)
    {
      alarmlow();
    }
  }
  else if (nivel >= NIVEL_ALTO)
  {
    full_read++;
    if (full_read >= sameReadings)
    {
      alarmfull();
    }
  }
  else
  {
    lowlvl = true;
    lvlfull = true;
  }

  // Draw the tank and info display
  if (!sensorFail)
  {
    tank.levels();
    lcd.setCursor(7, 3);
    lcd.print("        ");
    lcd.setCursor(7, 3);
    lcd.print(columnaLiquida <= 0 ? 0 : litros);
    lcd.setCursor(6, 1);
    lcd.print("          ");
    lcd.setCursor(7, 1);
    lcd.print(nivel);
    lcd.setCursor(6, 2);
    lcd.print("          ");
    lcd.setCursor(7, 2);
    lcd.print(averagedistance);
    // Fixed Text
    lcd.setCursor(0, 1);
    lcd.print("Nivel:");
    lcd.setCursor(10, 1);
    lcd.print("%");
    lcd.setCursor(0, 2);
    lcd.print("Dist.:");
    lcd.setCursor(13, 2);
    lcd.print("cm");
    lcd.setCursor(0, 3);
    lcd.print("Vol. :");
    lcd.setCursor(15, 3);
    lcd.print("L");
    lcd.setCursor(2, 0);
    lcd.print("                "); // Clear text alarm
  }
  else
  {
    createChars();
    lcd.clear();
    printBigCharacters(data2, 2, 1); // Print ERROR sensor readings
    buzzer_notify();
  }
  // Sleep LCD. Control backlight lcd
  currentMillis = millis();
  if (currentMillis - startMillis >= sleep_time) // Check the period has elapsed
  {
    digitalWrite(ledback, LOW); // turn off backlight
    lcd.setCursor(19, 0);
    lcd.print(" ");
    ledbacklight = false;
    startMillis = currentMillis;
  }
  if (button.pressed()) // get back backlight using a button
  {
    digitalWrite(ledback, HIGH);
    lcd.setCursor(19, 0);
    lcd.print("*");
    ledbacklight = true;
    startMillis = currentMillis;
  }
}
