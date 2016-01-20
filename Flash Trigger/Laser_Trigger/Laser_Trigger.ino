
//Laser Pointer 

// named constants for the switch and laser pins
const int optoPin = 4;           // Flash Trigger Pin
const int laserPin =  9;         // Laser Power
const int laserRecevier =  10;   // Laser Recevier
const int dropTime = 248;        // How long to allow the object to drop
const int flashDelay = 2000;     // How long between flashes
int laserSwitch = LOW;           // 

void setup() {
  Serial.begin(9600); // starts serial port with baud = 9600
  // initialize the Laser Pin to power Laser
  pinMode(laserPin, OUTPUT);
  // initialize the laserRecevier
  pinMode(laserRecevier, INPUT);
  // Init Flash Trigger Pint
  pinMode(optoPin, OUTPUT);
}

void loop() {
  // read the state of the switch value:
  laserSwitch = digitalRead(laserRecevier);

  // Laser Switch Logic
  if (laserSwitch == LOW) {
    delay(dropTime);
    digitalWrite(optoPin, HIGH);
    // Reset
    digitalWrite(optoPin, LOW);
    delay(flashDelay);
  }
  else {
    // Keep Flash Off
    digitalWrite(optoPin, LOW);
  }
}
