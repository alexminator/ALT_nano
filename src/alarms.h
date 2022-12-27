// Función de Anti-debounce (Evitar el rebote del pulsador)
void anti_debounce(byte boton)
{
   delay(100);
   while (digitalRead(boton));
   delay(100);
}

void enter()
{
   keypressed = digitalRead(keyPin);
   if (keypressed)
   {
      anti_debounce(keyPin);
      KP = 1;
   }
}

void alarmfull()
{
   if (!ledbacklight)
   {
      digitalWrite (ledback, HIGH); // Turn On LCD for alarm
   }
   
   while (lvlfull)
   {
      enter();
      lcd.setCursor(1, 0);
      lcd.print("ALARMA NIVEL ALTO");
      buzzer_finish();

      if (KP == 1)
      {
         KP = 0;
         noTone(BUZZER_PIN);
         lvlfull = false;
         lcd.clear();
         break;
      }
   }
}

void alarmlow()
{
   if (!ledbacklight)
   {
      digitalWrite (ledback, HIGH); // Turn On LCD for alarm
   }
   

   while (lowlvl)
   {
      enter();
      lcd.setCursor(1, 0);
      lcd.print("ALARMA NIVEL BAJO");
      buzzer_finish();

      if (KP == 1)
      {
         KP = 0;
         noTone(BUZZER_PIN);
         lowlvl = false;
         lcd.clear();
         break;
      }
   }
}

