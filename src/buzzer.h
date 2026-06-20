//#########################BUZZER CONTROL#############################################################

// Mario intro melody note frequencies
static const int NOTE_C7 = 2093;
static const int NOTE_E7 = 2637;
static const int NOTE_G7 = 3136;
static const int NOTE_G6 = 1568;

void buzzer_intro() {  // Tone for intro (Mario melody, blocking but only at startup)
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
    if (melody[thisNote] > 0) {
      tone(BUZZER_PIN, melody[thisNote], noteDuration);
      delay(noteDuration);
    }
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
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
