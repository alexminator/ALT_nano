#include <Arduino.h>

// Declare the debugging level then include the header file
#define DEBUGLEVEL DEBUGLEVEL_DEBUGGING
// #define DEBUGLEVEL DEBUGLEVEL_NONE
#include "debug.h"

//-------------Buzzer---------
#define BUZZER_PIN 4 // Buzzer BUZZER_PIN

//-------------lcd---------
char data1[] = "ALT";
char data2[] = "ERROR";
byte char_x = 0;
byte char_y = 0;
int ledback = 12;

// otras variables
bool sensorFail = false;
int nivel = 0; // nivel en %
bool lvlfull = true;
bool lowlvl = true;

//---------Variables del tanque---------
#define DIST_TOPE 104        // nivel maximo, medida con el tanque vacio en cm
const int NIVEL_BAJO = 20;   // nivel bajo porcentual a partir del cual doy alarma bajo nivel
const int NIVEL_ALTO = 100;  // nivel alto porcentual a partir del cual doy alarma de tanque lleno
const float ancho = 195.5;   // cm
const float largo = 200.0;   // cm
const float tabiqueA = 14.5; // ancho tabique cm
const float tabiqueL = 200;  // largo tabique cm

//-------------filter variables---------
float averagedistance = 0;

//------------- Button---------
#define keyPin 3 // button is connected to pin 3(INT 1)
int keypressed;
boolean KP; // key flag

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

//-------------tiempo en pantalla---------
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long sleep_time = 60000; // Tiempo en seg para apagar la luz de fondo
bool ledbacklight;

//------------- librerias---------
#include <LiquidCrystal.h>
// LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
#include <SoftwareSerial.h>
#include "font.h"
#include "sensor.h"
#include "filtro.h"
#include "lcd.h"
#include "buzzer.h"
#include "util.h"
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
  // delay(1000); // tiempo espera para que cargue todo
  lcd.clear();
}

void loop()
{

  button.read();

  if (button.pressed())
  {
    KP = 1;
  }

  // se obtiene el nivel
  get_level();

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
    lcd.print("                "); // Clear text error de lectura

    if (nivel == 0)
    {
      empty();
    }
    else if (nivel <= 10)
    {
      ten();
    }
    else if (nivel <= 20)
    {
      twenty();
    }
    else if (nivel <= 30)
    {
      thirty();
    }
    else if (nivel <= 40)
    {
      forty();
    }
    else if (nivel <= 50)
    {
      fifty();
    }
    else if (nivel <= 60)
    {
      sixty();
    }
    else if (nivel <= 70)
    {
      seventy();
    }
    else if (nivel <= 80)
    {
      eighty();
    }
    else if (nivel <= 90)
    {
      ninety();
    }
    else if (nivel < 100)
    {
      full();
    }
    else if (nivel >= 100)
    {
      full();
    }
  } else {
    createChars();
    lcd.clear();
    printBigCharacters(data2, 2, 1); //Print ERROR sensor readings
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

  if (KP == 1) // get back backlight using a button
  {
    KP = 0;
    digitalWrite(ledback, HIGH);
    lcd.setCursor(19, 0);
    lcd.print("*");
    ledbacklight = true;
    startMillis = currentMillis;
  }
}