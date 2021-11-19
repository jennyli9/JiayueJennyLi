
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_FS5, NOTE_FS5, NOTE_E5, 
  NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_E5, NOTE_NO, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_B4,
  NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_CS5, NOTE_A4, NOTE_NO, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_NO,
  NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_FS5, NOTE_FS5, NOTE_E5,
  NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_A5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4,
  NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_A4, NOTE_NO, NOTE_A4, NOTE_E5, NOTE_D5,
};

// note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
int noteDurations[] = {
  12, 10, 10, 8, 4, 4, 2, 
  12, 10, 10, 8, 4, 12, 8, 4, 6, 6,
  12, 10, 10, 8, 4, 4, 2, 8, 8, 6, 12, 6, 2, 6,
  12, 10, 10, 8, 4, 4, 2,
  12, 10, 10, 8, 4, 8, 4, 6, 4,
  12, 10, 10, 8, 8, 6, 2, 4, 6, 8, 4, 4,
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
