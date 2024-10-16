void alarmfull()
{
   if (!ledbacklight)
   {
      digitalWrite(LEDBACK, HIGH); // Turn On LCD for alarm
      lcd.setCursor(19, 0);
      lcd.print("*");
   }

   while (lvlfull)
   {
      lcd.setCursor(1, 0);
      lcd.print("ALARMA NIVEL ALTO");
      buzzer_finish();
      button.read();
      if (button.held())
      {
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
      digitalWrite(LEDBACK, HIGH); // Turn On LCD for alarm
      lcd.setCursor(19, 0);
      lcd.print("*");
   }

   while (lowlvl)
   {
      lcd.setCursor(1, 0);
      lcd.print("ALARMA NIVEL BAJO");
      buzzer_finish();
      button.read();
      if (button.held())
      {
         noTone(BUZZER_PIN);
         lowlvl = false;
         lcd.clear();
         break;
      }
   }
}
