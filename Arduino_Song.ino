
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_FS4, NOTE_FS4, NOTE_E4, 
  NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_E4, NOTE_NO, NOTE_E4, NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_NO,
  NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_D4, NOTE_E4, NOTE_CS4, NOTE_CS4, NOTE_A3, NOTE_NO, NOTE_A3, NOTE_E4, NOTE_D4, NOTE_NO,
  NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_FS4, NOTE_FS4, NOTE_E4,
  NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_A4, NOTE_NO, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_B3,
  NOTE_A3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_D4, NOTE_NO, NOTE_E4, NOTE_CS4, NOTE_A3, NOTE_NO, NOTE_A3, NOTE_E4, NOTE_D4,
};

// note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
int noteDurations[] = {
  12, 10, 10, 8, 4, 4, 2, 
  12, 10, 10, 6, 8, 12, 8, 4, 6, 6, 12,
  12, 10, 10, 8, 4, 4, 2, 8, 8, 6, 12, 6, 2, 6,
  12, 10, 10, 8, 4, 4, 2,
  12, 10, 10, 8, 4, 12, 10, 4, 6, 4,
  12, 10, 10, 8, 6, 12,  6, 2, 4, 8, 6, 4, 4,
};

void setup() {
  // iterate over the notes of the melody:
  int size = sizeof(noteDurations) / sizeof(int);

  for (int thisNote = 0; thisNote < size; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.35;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
