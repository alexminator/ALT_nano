//#########################BUZZER CONTROL#############################################################

void buzz(int targetPin, long frequency, long length) {
  if (frequency <= 0) return; // Prevent division by zero and skip silence

  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
    for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
}

// Mario intro melody note frequencies
// Using const int instead of #define for scoping and type safety
static const int NOTE_C7 = 2093;
static const int NOTE_E7 = 2637;
static const int NOTE_G7 = 3136;
static const int NOTE_G6 = 1568;

void buzzer_intro (){   // Tone for intro

  //Mario intro melody (stored in flash with static const)
  static const int melody[] = {
    NOTE_E7, NOTE_E7, 0, NOTE_E7,
    0, NOTE_C7, NOTE_E7, 0,
    NOTE_G7, 0, 0,  0,
    NOTE_G6, 0, 0, 0,
  };

  static const int tempo[] = {
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    };

  const int size = sizeof(melody) / sizeof(melody[0]);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      wdt_reset(); // Keep watchdog happy during long melody (~3s total)
      int noteDuration = 1000 / tempo[thisNote];
      buzz(BUZZER_PIN, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(BUZZER_PIN, 0, noteDuration);
    }
}

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
}

// Non-blocking ascending arpeggio for all alarms
// Loops continuously while active: 6 notes in ascending pattern
// Uses a state machine that advances one step per call
struct BuzzerNotify {
    bool active;
    uint8_t currentNote;
    unsigned long lastNoteTime;
};

BuzzerNotify buzzerNotify = {false, 0, 0};

// The ascending arpeggio notes (same as buzzer_notify())
static const int NOTIFY_NOTES[] = { 1318, 1567, 2637, 2093, 2349, 3135 };
static const unsigned long NOTIFY_CYCLE_MS[] = { 114, 114, 114, 114, 114, 450 }; // ms between note starts (last has pause before repeat)
static const unsigned long NOTIFY_TONE_MS[] = { 57, 57, 57, 57, 57, 275 }; // tone duration
static const uint8_t NOTIFY_NOTE_COUNT = 6;

void buzzer_notify_start() {
    buzzerNotify.active = true;
    buzzerNotify.currentNote = 0;
    buzzerNotify.lastNoteTime = 0; // Force immediate first note on next update
}

void buzzer_notify_stop() {
    buzzerNotify.active = false;
    noTone(BUZZER_PIN);
}

void buzzer_notify_update() {
    if (!buzzerNotify.active) return;

    unsigned long now = millis();
    if (now - buzzerNotify.lastNoteTime >= NOTIFY_CYCLE_MS[buzzerNotify.currentNote]) {
        buzzerNotify.lastNoteTime = now;
        tone(BUZZER_PIN, NOTIFY_NOTES[buzzerNotify.currentNote], NOTIFY_TONE_MS[buzzerNotify.currentNote]);

        buzzerNotify.currentNote++;
        if (buzzerNotify.currentNote >= NOTIFY_NOTE_COUNT) {
            buzzerNotify.currentNote = 0; // Loop continuously
        }
    }
}
