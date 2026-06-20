//#########################BUZZER CONTROL#############################################################

void buzz(int targetPin, long frequency, long length) {
<<<<<<< HEAD
  if (frequency <= 0) return; // Prevent division by zero and skip silence

=======
  
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
    for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
}

<<<<<<< HEAD
// Mario intro melody note frequencies
// Using const int instead of #define for scoping and type safety
static const int NOTE_C7 = 2093;
static const int NOTE_E7 = 2637;
static const int NOTE_G7 = 3136;
static const int NOTE_G6 = 1568;

void buzzer_intro (){   // Tone for intro

//Mario intro melody (stored in flash with static const)
static const int melody[] = {
=======
void buzzer_intro (){   // Tone for intro
#define NOTE_C7  2093
#define NOTE_E7  2637
#define NOTE_G7  3136
#define NOTE_G6  1568

//Mario intro melody
int melody[] = {
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
};

<<<<<<< HEAD
static const int tempo[] = {
=======
int tempo[] = {
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
<<<<<<< HEAD
  };

 const int size = sizeof(melody) / sizeof(melody[0]);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      wdt_reset(); // Keep watchdog happy during long melody (~3s total)
=======
 
  };

 int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
      int noteDuration = 1000 / tempo[thisNote];
      buzz(BUZZER_PIN, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(BUZZER_PIN, 0, noteDuration);
    }
}

<<<<<<< HEAD
void buzzer_notify()  // Tone for notify (ascending arpeggio)
{
  // Note: duration is ~57ms per note (~17.6 notes/sec), last note held longer
  static const float NOTE_DURATION = 56.8;
  static const float LAST_DURATION = 275.2;

  static const int notes[] = { 1318, 1567, 2637, 2093, 2349, 3135 };

  for (int i = 0; i < 5; i++) {
    tone(BUZZER_PIN, notes[i], NOTE_DURATION);
    delay(NOTE_DURATION);
    delay(NOTE_DURATION);
  }
  // Last note held longer
  tone(BUZZER_PIN, notes[5], LAST_DURATION);
  delay(LAST_DURATION);
=======
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
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
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
<<<<<<< HEAD
    wdt_reset(); // Keep watchdog happy during longer loops
=======
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
    delay(delay_time);
  }
  for (float f = f_max; f > f_min; f -= step_size)
  {
    tone(BUZZER_PIN, f, 100);
<<<<<<< HEAD
    wdt_reset(); // Keep watchdog happy during longer loops
=======
>>>>>>> 73c5fe60ae6bf27bc7dca2a79b0924206a753830
    delay(delay_time);
  }
}