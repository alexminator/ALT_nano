// Timer for non-blocking alarm buzzer
unsigned long lastAlarmBuzzer = 0;
const unsigned long ALARM_BUZZER_INTERVAL = 2000; // play buzzer every 2 seconds

void alarmcheck()
{
   unsigned long now = millis();

   if (nivel <= NIVEL_BAJO)
   {
      low_read++;
      if (low_read >= sameReadings)
      {
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
      }
   }
   else if (nivel >= NIVEL_ALTO)
   {
      full_read++;
      if (full_read >= sameReadings)
      {
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
      }
   }
   else
   {
      low_read = 0;
      full_read = 0;
   }
}
