<<<<<<< HEAD
// Timer for non-blocking alarm buzzer
unsigned long lastAlarmBuzzer = 0;
const unsigned long ALARM_BUZZER_INTERVAL = 2000; // play buzzer every 2 seconds

void alarmcheck()
{
   unsigned long now = millis();

=======
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
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
   if (nivel <= NIVEL_BAJO)
   {
      low_read++;
      if (low_read >= sameReadings)
      {
<<<<<<< HEAD
         if (!ledbacklight) {
            digitalWrite(LEDBACK, HIGH);
            startMillis = now; // Reset sleep timer when waking backlight
         }
         lcd.setCursor(1, 0);
         lcd.print("ALARMA NIVEL BAJO");
         if (now - lastAlarmBuzzer >= ALARM_BUZZER_INTERVAL) {
            buzzer_finish();
            lastAlarmBuzzer = now;
         }
         button.read();
         if (button.held())
         {
            noTone(BUZZER_PIN);
            low_read = 0;
            lastAlarmBuzzer = 0;
            lcd.clear();
         }
=======
         alarmlow();
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
      }
   }
   else if (nivel >= NIVEL_ALTO)
   {
      full_read++;
      if (full_read >= sameReadings)
      {
<<<<<<< HEAD
         if (!ledbacklight) {
            digitalWrite(LEDBACK, HIGH);
            startMillis = now; // Reset sleep timer when waking backlight
         }
         lcd.setCursor(1, 0);
         lcd.print("ALARMA NIVEL ALTO");
         if (now - lastAlarmBuzzer >= ALARM_BUZZER_INTERVAL) {
            buzzer_finish();
            lastAlarmBuzzer = now;
         }
         button.read();
         if (button.held())
         {
            noTone(BUZZER_PIN);
            full_read = 0;
            lastAlarmBuzzer = 0;
            lcd.clear();
         }
=======
         alarmfull();
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
      }
   }
   else
   {
<<<<<<< HEAD
      low_read = 0;
      full_read = 0;
   }
}
=======
      lowlvl = true;
      lvlfull = true;
   }
}


>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
