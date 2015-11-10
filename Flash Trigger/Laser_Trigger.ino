
//Laser Pointer 

// named constants for the switch and laser pins
const int switchPin = 2; // Push Button Switch
const int optoPin = 3; // Flash Trigger Pin
const int laserPin =  9; // Laser Power
const int laserRecevier =  10; // Laser Recevier
const int flashLength = 0; //How long the flash will be on (ms)
int pushSwitch = LOW;  // variable for reading the switch's status
int laserSwitch = LOW;

void setup() {
  Serial.begin(9600); // starts serial port with baud = 9600
  // initialize the Laser Pin to power Laser
  pinMode(laserPin, OUTPUT);
  // initialize the switch pin for push button switch
  pinMode(switchPin, INPUT);
  // initialize the laserRecevier
  pinMode(laserRecevier, INPUT);
  // Init Flash Trigger Pint
  pinMode(optoPin, OUTPUT);
}

void loop() {
  // read the state of the switch value:
  pushSwitch = digitalRead(switchPin);
  laserSwitch = digitalRead(laserRecevier);

  // Push Button Switch Logic
  if (pushSwitch == LOW) {
    // turn laser on, and keep flash off
    digitalWrite(laserPin, HIGH);
    digitalWrite(optoPin, LOW);
  }
  else {
    // trigger flash and turn laser off
    digitalWrite(laserPin, LOW);
    digitalWrite(optoPin, HIGH);
    delay(flashLength);
    digitalWrite(optoPin, LOW);
  }

  // Laser Switch Logic
  if (laserSwitch == HIGH) {
    // Trigger Flash
    digitalWrite(optoPin, HIGH);
    delay(flashLength);
    digitalWrite(optoPin, LOW);
  }
  else {
    // Keep Flash Off
    digitalWrite(optoPin, LOW);
  }
  
  boolean val = digitalRead(laserRec);
  Serial.println(val);
}
