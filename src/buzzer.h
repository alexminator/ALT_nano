//#########################BUZZER CONTROL#############################################################
void buzz(int targetPin, long frequency, long length) {
  
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
    for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
}

void buzzer_intro (){   // Tone for intro
#define NOTE_C7  2093
#define NOTE_E7  2637
#define NOTE_G7  3136
#define NOTE_G6  1568

//Mario intro melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
};

int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  };

 int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo[thisNote];
      buzz(BUZZER_PIN, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(BUZZER_PIN, 0, noteDuration);
    }
}

void buzzer_notify()  // Tone for notify
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
  tone(BUZZER_PIN, 3135, 275.18125);
  delay(275.18125);
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