#include <Arduino.h>

// Declare the debugging level then include the header file
//#define DEBUGLEVEL DEBUGLEVEL_DEBUGGING
#define DEBUGLEVEL DEBUGLEVEL_NONE
#include "debug.h"
#include <Tank.h>

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
#define DIST_TOPE 104        // nivel maximo, medida con el tanque vacio en cm
const int NIVEL_BAJO = 20;   // nivel bajo porcentual a partir del cual doy alarma bajo nivel
const int NIVEL_ALTO = 100;  // nivel alto porcentual a partir del cual doy alarma de tanque lleno
const float ancho = 195.5;   // cm
const float largo = 200.0;   // cm
const float tabiqueA = 14.5; // ancho tabique cm
const float tabiqueL = 200;  // largo tabique cm
float columnaLiquida;
float VolumenDinamicoTabique;
float litros;

Tank* draw = new Tank(&lcd);

//-------------filter variables---------
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
// Creando el objeto button con  {pin, lastReading, lastDebounceTime, state}
Button button = {keyPin, HIGH, 0, 0};

// Variables del sensor ultrasonico
bool sensorFail = false;
int nivel = 0; // nivel en %
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

  // methods for sensor get_dist, get_level and get volume
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

    if (distance > 40)
      distance += 3.0;
    else
      distance += 2.0;

    debuglnD("Distancia en tiempo real: " + String(distance));

    return distance;
  }

  int get_level()
  {
    float distance = get_dist();

    if (distance > 2 && distance < DIST_TOPE)
    {                                            // Descarta errores del sensor, desecha las lecturas malas.
      averagedistance = movingAverage(distance); // valor final usando Moving average
      sensorFail = false;

      debuglnD("Distancia average: " + String(averagedistance));

      columnaLiquida = DIST_TOPE - averagedistance;
      nivel = map(columnaLiquida, 0, DIST_TOPE - 25, 0, 100); // 79 cm seria el nivel maximo en % por seguridad del sensor(25cm)

      debuglnD("Nivel en porciento: " + String(nivel));
    }
    else
    {
      sensorFail = true;
    }

    if (nivel < 0)
    {
      nivel = 0;
    }

    return nivel;
  }

  float get_volume()
  {
    VolumenDinamicoTabique = (tabiqueA * tabiqueL * columnaLiquida); // calculo del volumen del tabique hasta la altura del agua

    debuglnD("Volumen del tabique a una altura de " + String(columnaLiquida) + " cm es de " + String(VolumenDinamicoTabique) + " cm^3.");

    float volumenRealTanque = (ancho * largo * columnaLiquida) - VolumenDinamicoTabique;

    debuglnD("Volumen de agua: " + String(volumenRealTanque) + " cm^3.");

    litros = volumenRealTanque / 1000.0;

    return litros;
  }
};

Sensor ultraSonic = {trigPin, echoPin}; // Creando el objeto ultraSonic con {trigPin, echoPin}

struct Draw
{
  // state variables
  int level;
  // methods for draw a tank
  void levels()
  {
    if (nivel <= 5)
    {
      // vacio
      draw -> registerTank(0,WLe);
      draw -> registerTank(1,WRe);
      draw -> registerTank(2,WLBe);
      draw -> registerTank(3,WRBe);
      draw -> registerTank(4,Be);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 2);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 3);
      draw -> drawTank(WLBe);
      // bottom
      lcd.setCursor(17, 3);
      draw -> drawTank(Be);
      lcd.setCursor(18, 3);
      draw -> drawTank(Be);
      // wall rigth
      lcd.setCursor(19, 1);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 2);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 3);
      draw -> drawTank(WRBe);
      
    }
    else if (nivel <= 10)
    {
      // lleno 10%
      draw -> registerTank(0,WLe);
      draw -> registerTank(1,WRe);
      draw -> registerTank(2,BL10);
      draw -> registerTank(3,BR10);
      draw -> registerTank(4,BC10);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 2);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 3);
      draw -> drawTank(BL10);
      // bottom
      lcd.setCursor(17, 3);
      draw -> drawTank(BC10);
      lcd.setCursor(18, 3);
      draw -> drawTank(BC10);
      // wall rigth
      lcd.setCursor(19, 1);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 2);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 3);
      draw -> drawTank(BR10);
    }
    else if (nivel <= 20)
    {
      // lleno 20%
      draw -> registerTank(0,WLe);
      draw -> registerTank(1,WRe);
      draw -> registerTank(2,BL20);
      draw -> registerTank(3,BR20);
      draw -> registerTank(4,BC20);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 2);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 3);
      draw -> drawTank(BL20);
      // bottom
      lcd.setCursor(17, 3);
      draw -> drawTank(BC20);
      lcd.setCursor(18, 3);
      draw -> drawTank(BC20);
      // wall rigth
      lcd.setCursor(19, 1);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 2);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 3);
      draw -> drawTank(BR20);
    }
    else if (nivel <= 30)
    {
      // lleno 30%
      draw -> registerTank(0,WLe);
      draw -> registerTank(1,WRe);
      draw -> registerTank(2,BL30);
      draw -> registerTank(3,BR30);
      draw -> registerTank(4,BC30);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 2);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 3);
      draw -> drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw -> drawTank(BC30);
      lcd.setCursor(18, 3);
      draw -> drawTank(BC30);
      // wall rigth
      lcd.setCursor(19, 1);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 2);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 3);
      draw -> drawTank(BR30);
    }
    else if (nivel <= 40)
    {
      // lleno 40%
      draw -> registerTank(0,WLe);
      draw -> registerTank(1,WRe);
      draw -> registerTank(2,WL48);
      draw -> registerTank(3,WR48);
      draw -> registerTank(4,C48);
      draw -> registerTank(5,BL30);
      draw -> registerTank(6,BR30);
      draw -> registerTank(7,BC30);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      draw -> drawTank(WLe);
      lcd.setCursor(16, 2);
      draw -> drawTank(WL48);
      lcd.setCursor(16, 3);
      draw -> drawTank(BL30);
      // bottom
      lcd.setCursor(17, 3);
      draw -> drawTank(BC30);
      lcd.setCursor(18, 3);
      draw -> drawTank(BC30);
      lcd.setCursor(17, 2);
      draw -> drawTank(C48);
      lcd.setCursor(18, 2);
      draw -> drawTank(C48);
      // wall rigth
      lcd.setCursor(19, 1);
      draw -> drawTank(WRe);
      lcd.setCursor(19, 2);
      draw -> drawTank(WR48);
      lcd.setCursor(19, 3);
      draw -> drawTank(BR30);
    }
    else if (nivel <= 50)
    {
      // lleno 50%
      lcd.createChar(1, WLe);
      lcd.createChar(2, WRe);
      lcd.createChar(3, WL59);
      lcd.createChar(4, WR59);
      lcd.createChar(5, C59);
      lcd.createChar(6, BL30);
      lcd.createChar(7, BR30);
      lcd.createChar(8, BC30);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      lcd.print(char(1));
      lcd.setCursor(16, 2);
      lcd.print(char(3));
      lcd.setCursor(16, 3);
      lcd.print(char(6));
      // bottom
      lcd.setCursor(17, 3);
      lcd.print(char(8));
      lcd.setCursor(18, 3);
      lcd.print(char(8));
      lcd.setCursor(17, 2);
      lcd.print(char(5));
      lcd.setCursor(18, 2);
      lcd.print(char(5));
      // wall rigth
      lcd.setCursor(19, 1);
      lcd.print(char(2));
      lcd.setCursor(19, 2);
      lcd.print(char(4));
      lcd.setCursor(19, 3);
      lcd.print(char(7));
    }
    else if (nivel <= 60)
    {
      // lleno 60%
      lcd.createChar(1, WLe);
      lcd.createChar(2, WRe);
      lcd.createChar(3, WL61);
      lcd.createChar(4, WR61);
      lcd.createChar(5, C61);
      lcd.createChar(6, BL30);
      lcd.createChar(7, BR30);
      lcd.createChar(8, BC30);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      lcd.print(char(1));
      lcd.setCursor(16, 2);
      lcd.print(char(3));
      lcd.setCursor(16, 3);
      lcd.print(char(6));
      // bottom
      lcd.setCursor(17, 3);
      lcd.print(char(8));
      lcd.setCursor(18, 3);
      lcd.print(char(8));
      lcd.setCursor(17, 2);
      lcd.print(char(5));
      lcd.setCursor(18, 2);
      lcd.print(char(5));
      // wall rigth
      lcd.setCursor(19, 1);
      lcd.print(char(2));
      lcd.setCursor(19, 2);
      lcd.print(char(4));
      lcd.setCursor(19, 3);
      lcd.print(char(7));
    }
    else if (nivel <= 70)
    {
      // lleno 70%
      lcd.createChar(1, WLe);
      lcd.createChar(2, WRe);
      lcd.createChar(3, WL70);
      lcd.createChar(4, WR70);
      lcd.createChar(5, BL30);
      lcd.createChar(6, BR30);
      lcd.createChar(7, BC30);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      lcd.print(char(1));
      lcd.setCursor(16, 2);
      lcd.print(char(3));
      lcd.setCursor(16, 3);
      lcd.print(char(5));
      // bottom
      lcd.setCursor(17, 3);
      lcd.print(char(8));
      lcd.setCursor(18, 3);
      lcd.print(char(7));
      lcd.setCursor(17, 2);
      lcd.print(char(7));
      lcd.setCursor(18, 2);
      lcd.print(char(7));
      // wall rigth
      lcd.setCursor(19, 1);
      lcd.print(char(2));
      lcd.setCursor(19, 2);
      lcd.print(char(4));
      lcd.setCursor(19, 3);
      lcd.print(char(6));
    }
    else if (nivel <= 80)
    {
      // lleno 80%
      lcd.createChar(1, WL48);
      lcd.createChar(2, WR48);
      lcd.createChar(3, WL70);
      lcd.createChar(4, WR70);
      lcd.createChar(5, C48);
      lcd.createChar(6, BL30);
      lcd.createChar(7, BR30);
      lcd.createChar(8, BC30);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      lcd.print(char(1));
      lcd.setCursor(16, 2);
      lcd.print(char(3));
      lcd.setCursor(16, 3);
      lcd.print(char(6));
      // bottom
      lcd.setCursor(17, 3);
      lcd.print(char(8));
      lcd.setCursor(18, 3);
      lcd.print(char(8));
      lcd.setCursor(17, 1);
      lcd.print(char(5));
      lcd.setCursor(18, 1);
      lcd.print(char(5));
      lcd.setCursor(17, 2);
      lcd.print(char(8));
      lcd.setCursor(18, 2);
      lcd.print(char(8));
      // wall rigth
      lcd.setCursor(19, 1);
      lcd.print(char(2));
      lcd.setCursor(19, 2);
      lcd.print(char(4));
      lcd.setCursor(19, 3);
      lcd.print(char(7));
    }
    else if (nivel <= 90)
    {
      // lleno 90%
      lcd.createChar(1, WL59);
      lcd.createChar(2, WR59);
      lcd.createChar(3, WL70);
      lcd.createChar(4, WR70);
      lcd.createChar(5, C59);
      lcd.createChar(6, BL30);
      lcd.createChar(7, BR30);
      lcd.createChar(8, BC30);
      lcd.setCursor(16, 1);
      lcd.print("    ");
      lcd.setCursor(16, 2);
      lcd.print("    ");
      lcd.setCursor(16, 3);
      lcd.print("    ");
      // wall left
      lcd.setCursor(16, 1);
      lcd.print(char(1));
      lcd.setCursor(16, 2);
      lcd.print(char(3));
      lcd.setCursor(16, 3);
      lcd.print(char(6));
      // bottom
      lcd.setCursor(17, 1);
      lcd.print(char(5));
      lcd.setCursor(18, 1);
      lcd.print(char(5));
      lcd.setCursor(17, 2);
      lcd.print(char(8));
      lcd.setCursor(18, 2);
      lcd.print(char(8));
      lcd.setCursor(17, 3);
      lcd.print(char(8));
      lcd.setCursor(18, 3);
      lcd.print(char(8));
      // wall rigth
      lcd.setCursor(19, 1);
      lcd.print(char(2));
      lcd.setCursor(19, 2);
      lcd.print(char(4));
      lcd.setCursor(19, 3);
      lcd.print(char(7));
    }
    else if (nivel <= 100){
      // lleno 100%
    lcd.createChar(1, WL61);
    lcd.createChar(2, WR61);
    lcd.createChar(3, WL70);
    lcd.createChar(4, WR70);
    lcd.createChar(5, C61);
    lcd.createChar(6, BL30);
    lcd.createChar(7, BR30);
    lcd.createChar(8, BC30);
    lcd.setCursor(16, 1);
    lcd.print("    ");
    lcd.setCursor(16, 2);
    lcd.print("    ");
    lcd.setCursor(16, 3);
    lcd.print("    ");
    // wall left
    lcd.setCursor(16, 1);
    lcd.print(char(1));
    lcd.setCursor(16, 2);
    lcd.print(char(3));
    lcd.setCursor(16, 3);
    lcd.print(char(6));
    // bottom
    lcd.setCursor(17, 3);
    lcd.print(char(8));
    lcd.setCursor(18, 3);
    lcd.print(char(8));
    lcd.setCursor(17, 1);
    lcd.print(char(5));
    lcd.setCursor(18, 1);
    lcd.print(char(5));
    lcd.setCursor(17, 2);
    lcd.print(char(8));
    lcd.setCursor(18, 2);
    lcd.print(char(8));
    // wall rigth
    lcd.setCursor(19, 1);
    lcd.print(char(2));
    lcd.setCursor(19, 2);
    lcd.print(char(4));
    lcd.setCursor(19, 3);
    lcd.print(char(7));
    }
  }
};

Draw tank = {nivel};    // Creando el objeto dibujar tanque con {nivel}

//-------------tiempo en pantalla---------
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long sleep_time = 60000; // Tiempo en seg para apagar la luz de fondo 1mint
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
  pinMode(BUZZER_PIN, OUTPUT); // salida del buzzer
  pinMode(keyPin, INPUT);      // boton
  pinMode(ledback, OUTPUT);    // backlight
  pinMode(trigPin, OUTPUT);    // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);     // Sets the echoPin as an Input

  // Encendemos Luz de fondo
  digitalWrite(ledback, HIGH);

  // Imprimimos el LOGO
  createChars();
  printBigCharacters(data1, 5, 0);
  lcd.setCursor(1, 2);
  lcd.print("Another Level Tank");
  lcd.setCursor(4, 3);
  lcd.print("..Loading..");
  lcd.display();
  delay(1000);
  buzzer_notify();
  delay(1000);
  lcd.clear();
}

void loop()
{
  button.read();

  // se obtiene el nivel y volumen
  nivel = ultraSonic.get_level();
  litros = ultraSonic.get_volume();

  // Alarmas
  if (nivel <= NIVEL_BAJO)
  {
    alarmlow();
  }

  if (nivel > NIVEL_BAJO)
  {
    lowlvl = true;
  }

  if (nivel < NIVEL_ALTO)
  {
    lvlfull = true;
  }

  if (nivel >= NIVEL_ALTO)
  {
    alarmfull();
  }

  // Draw the tank and info display
  if (!sensorFail)
  {
    tank.levels();

    if (columnaLiquida <= 0)
    {
      lcd.setCursor(7, 3);
      lcd.print("        ");
      lcd.setCursor(7, 3);
      lcd.print(0);
    }
    else
    {
      lcd.setCursor(7, 3);
      lcd.print("        ");
      lcd.setCursor(7, 3);
      lcd.print(litros);
    }

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
