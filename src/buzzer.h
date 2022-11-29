//#########################BUZZER CONTROL#############################################################

void buzzer_notify()  // Tone for intro
{
  tone(BUZZER_PIN, 1318, 56.818125);
  delay(56.818125);
  delay(56.818125);
  tone(BUZZER_PIN, 1567, 56.818125);
  delay(56.818125);
  delay(56.818125);
  tone(BUZZER_PIN, 2637, 56.818125);
  delay(56.818125);
  delay(56.818125);
  tone(BUZZER_PIN, 2093, 56.818125);
  delay(56.818125);
  delay(56.818125);
  tone(BUZZER_PIN, 2349, 56.818125);
  delay(56.818125);
  delay(56.818125);
  tone(BUZZER_PIN, 3135, 568.18125);
  delay(568.18125);
}
void buzzer_finish() // Tone for alarm
{
  float rise_fall_time = 180;
  int steps = 50;
  float f_max = 2600;
  float f_min = 1000;
  float delay_time = rise_fall_time / steps;
  float step_size = (f_max - f_min) / steps;
  for (float f = f_min; f < f_max; f += step_size)
  {
    tone(BUZZER_PIN, f, 100);
    delay(delay_time);
  }
  for (float f = f_max; f > f_min; f -= step_size)
  {
    tone(BUZZER_PIN, f, 100);
    delay(delay_time);
  }
}