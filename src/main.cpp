#include <Arduino.h>
#include <EasyButton.h>

// Declare the debugging level then include the header file
#define DEBUGLEVEL DEBUGLEVEL_DEBUGGING
//#define DEBUGLEVEL DEBUGLEVEL_NONE
#include "debug.h"

//-------------Buzzer---------
#define BUZZER_PIN 4 // Buzzer BUZZER_PIN

//-------------lcd---------
char data1[] = "ALT";
char data2[] = "ERROR";
byte char_x = 0;
byte char_y = 0;

// otras variables
bool aviso = true;
bool sensorFail = false;
bool shutDownWarningForLowUmbral = false;
int nivel = 0; // nivel en porciento

//---------Variables del tanque---------
#define DIST_TOPE 104        // nivel maximo, medida con el tanque vacio en cm
const int NIVEL_BAJO = 20;   // nivel bajo porcentual a partir del cual doy alarma bajo nivel
const int NIVEL_ALTO = 100;  // nivel alto porcentual a partir del cual doy alarma de tanque lleno
const float ancho = 195.5;   // cm
const float largo = 200.0;   // cm
const float tabiqueA = 14.5; // ancho tabique cm
const float tabiqueL = 200;  // largo tabique cm

//-------------kalman variables---------
float R = 2.92E-03; // measuement variance; determined using excel and reading samples of raw sensor data which is constant
float Q = 1e-3;     // arbitaryly determined for this case. -5,-7(not working),-3
float Pc = 0.0;
float G = 0.0;
float P = 1.0;
float Xp = 0.0;
float Zp = 0.0;
float Xe = 0.0;

//------------- Button---------
#define keyPin 3                              // button is connected to pin 3
EasyButton button(keyPin, 100, true, false); // button initialization according documentation (pullup true)

//-------------Milis---------
int periodo = 1000; // 1 seg
unsigned long timenow = 0;

//-------------tiempo en pantalla---------
byte display_time = 0;
const int durationON = 30; // tiempo en seg con pantalla encendida
bool printSleep = false;
bool printSleepAtStart = true;
bool alwaysOnDisplay = false;
//------------- librerias---------
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <SoftwareSerial.h>
#include "font.h"
#include "sensor.h"
#include "filtro.h"
#include "lcd.h"
#include "buzzer.h"
#include "util.h"

void onButtonPressed()
{
  debuglnW("short");
  lcd.backlight(); // Activamos la luz de fondo
  printSleep = true;
  debuglnW("++++++++++++++++++++++++++++++++PANTALLA ON+++++++++++++++++++++++++++++++++++");
  buzzer_notify();
  display_time = 0;
  
}

void onSequenceAlarm()
{
  debuglnW("******************Apagando la Alarma de bajo Nivel*********************************************");
  noTone(BUZZER_PIN);
  shutDownWarningForLowUmbral = true;
}

//####################----SETUP----###############################################
void setup()
{
  Serial.begin(9600);

  // Activamos la LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  // Inicializamos los pines
  pinMode(BUZZER_PIN, OUTPUT);   // salida del buzzer
  pinMode(keyPin, INPUT_PULLUP); // boton
  pinMode(trigPin, OUTPUT);      // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);       // Sets the echoPin as an Input
  // Imprimimos el LOGO
  createChars();
  printBigCharacters(data1, 6, 0);

  lcd.setCursor(5, 3);
  lcd.print("..Loading..");
  lcd.display();
  delay(1000);
  buzzer_notify();
  delay(1000); // tiempo espera para que cargue todo
  lcd.clear();

  // Button initialization
  button.begin();
  button.onPressedFor(2000, onSequenceAlarm);
  // button.onSequence(3, 1000, onSequenceAlarm);
  button.onPressed(onButtonPressed);
}
//####################----LOOP----###############################################
void loop()
{

  button.read();

  display_time++; // contador para esperar durationON seg de info en pantalla
  if (durationON - display_time <= 5 && printSleepAtStart) //Muestra S (sleep) 5s antes de apagarse
  {
    lcd.setCursor(19, 0);
    lcd.print("S");
  }
  debuglnD("-----------------------------------------------------------------------------time: " + String(display_time));

  // se obtiene el nivel
  kalmanFilter();

  get_level();

  if (nivel <= NIVEL_BAJO && !shutDownWarningForLowUmbral)
  {
    for (int count = 1; count < 3; count++)
      buzzer_warning();
  }

  if (nivel > NIVEL_BAJO)
  {
    shutDownWarningForLowUmbral = false;
  }

  if (nivel < NIVEL_ALTO)
  {
    aviso = true;
  }

  if (nivel >= NIVEL_ALTO)
  {
    if (aviso)
    { // bandera para que suene una sola vez
      // for (int count=1;count<=3;count++)  //suena 2 veces
      buzzer_finish(); // solo hace falta que suene una sola vez
      aviso = false;
    }
  }

  if (printSleep && !printSleepAtStart)
  {
    lcd.setCursor(19, 0);
    lcd.print("S");
  }

  if (!sensorFail)
  {
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
    else if (nivel <= 100)
    {
      full();
    }
    else if (nivel > 100)
    {
      full();
    }
  }

  if (display_time == durationON)
  {
    printSleep = false;
    printSleepAtStart = false;
    if (millis() > timenow + periodo)
    {
      timenow = millis();
      lcd.noBacklight(); // turn off backlight
      debuglnW("++++++++++++++++++++++++++++++++PANTALLA OFF+++++++++++++++++++++++++++++++++++");
      display_time = 0;
    }
  }
  
}