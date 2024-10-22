void alarmfull()
{
   if (!ledbacklight)
   {
      digitalWrite(LEDBACK, HIGH); // Turn On LCD for alarm
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

void alarmcheck()
{
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
}


