// Función de Anti-debounce (Evitar el rebote del pulsador)

void alarmfull()
{
   if (!ledbacklight)
   {
      digitalWrite (ledback, HIGH); // Turn On LCD for alarm
      lcd.setCursor(19, 0);
      lcd.print("*");
   }
   
   while (lvlfull)
   {
      button.read();
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
      lcd.setCursor(19, 0);
      lcd.print("*");
   }
   

   while (lowlvl)
   {
      button.read();
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

