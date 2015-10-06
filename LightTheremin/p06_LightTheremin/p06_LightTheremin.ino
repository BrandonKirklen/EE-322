// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin
const int ledPin = 13;

void setup() {
  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
}

void loop() {
  int notes[90] = 
    { 55, 58, 62, 65, 69, 73, 78, 82, 87, 93, 98, 104, 
    110, 117, 123, 131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 
    247, 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 
    554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 1047, 1109, 1175, 
    1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976, 2093};
  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);

  // map the sensor values to a wide range of pitches
  int pitch = map(sensorValue, sensorLow, sensorHigh, 0, 90-25);
  //pitch = pitch - (pitch % 10);

  // play the tone for 20 ms on pin 8
  tone(8, notes[pitch], 90);

  // wait for a moment
  delay(20);
}

