// Unified non-blocking alarm system
// Uses the same buzzer_notify() arpeggio for all alarm types
bool alarmSilenced = false; // User dismissed alarm sound; re-arm only after condition clears

void alarm_handler()
{
   unsigned long now = millis();

   // Update level alarm counters only when sensor is working
   if (!sensorFail) {
      if (nivel <= NIVEL_BAJO) {
         if (low_read < sameReadings) low_read++;
      } else if (nivel >= NIVEL_ALTO) {
         if (full_read < sameReadings) full_read++;
      } else {
         low_read = 0;
         full_read = 0;
      }
   }

   // Determine if any alarm is active (priority: sensor error > low level > high level)
   bool alarmActive = sensorFail || (low_read >= sameReadings) || (full_read >= sameReadings);

   if (alarmActive) {
      // Wake backlight if asleep
      if (!ledbacklight) {
         digitalWrite(LEDBACK, HIGH);
         ledbacklight = true;
         startMillis = now;
      }

      // Start the non-blocking arpeggio if not already playing
      if (!alarmSilenced && !buzzerNotify.active) {
         buzzer_notify_start();
      }

      // Show alarm text on line 0 for level alarms (sensor error has big ERROR text from show_info)
      if (low_read >= sameReadings && !sensorFail) {
         lcd.setCursor(0, 0);
         lcd.print("ALARMA NIVEL BAJO   ");
      }
      if (full_read >= sameReadings && !sensorFail) {
         lcd.setCursor(0, 0);
         lcd.print("ALARMA NIVEL ALTO   ");
      }

      // Button silences the sound (text stays until condition clears)
      button.read();
      if (button.held()) {
         alarmSilenced = true;
         buzzer_notify_stop();
      }
   }
   else
   {
      // No alarm: clean up
      if (buzzerNotify.active) {
         buzzer_notify_stop();
      }
      alarmSilenced = false;

      // Clear alarm text from line 0 (show_info handles the display)
      lcd.setCursor(0, 0);
      lcd.print("                    ");
   }
}
