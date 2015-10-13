// create an array of notes
// the numbers below correspond to
// the frequencies of middle C, D, E, and F
int notes[] = {262, 294, 330, 349, 392, 440, 493};

void setup() {
  //start serial communication
  Serial.begin(9600);
}

void loop() {
  // create a local variable to hold the input on pin A0
  int keyVal = analogRead(A0);
  int duration = 50;
  // send the value from A0 to the Serial Monitor
  Serial.println(keyVal);

  // play the note corresponding to each value on A0
  if (keyVal == 1023) {
    // play the first frequency in the array on pin 8
    tone(8, notes[0], duration);
  }
  else if (keyVal >= 1000 && keyVal <= 1015) {
    // play the second frequency in the array on pin 8
    tone(8, notes[1], duration);
  }
  else if (keyVal >= 980 && keyVal <= 999) {
    // play the third frequency in the array on pin 8
    tone(8, notes[2], duration);
  }
  else if (keyVal >= 900 && keyVal <= 979) {
    // play the fourth frequency in the array on pin 8
    tone(8, notes[3], duration);
  }
  else if (keyVal >= 800 && keyVal <= 899) {
    // play the fourth frequency in the array on pin 8
    tone(8, notes[4], duration);
  }
  else if (keyVal >= 450 && keyVal <= 799) {
    // play the fourth frequency in the array on pin 8
    tone(8, notes[5], duration);
  }
  else if (keyVal >= 2 && keyVal <= 400) {
    // play the fourth frequency in the array on pin 8
    tone(8, notes[6], duration);
  }
  else {
    // if the value is out of range, play no tone
    noTone(8);
  }
}

