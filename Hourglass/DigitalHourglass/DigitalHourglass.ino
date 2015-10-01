const int switchPin = 8;

unsigned long timeOfLight = 0; 
int switchState = 0; 
int prevSwitchState = 0; 
int led = 2; 


unsigned long secPerLight = 1000;

void setup() {
  // set the LED pins as outputs
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - timeOfLight > secPerLight) {
    timeOfLight = currentTime;
    digitalWrite(led, HIGH);
    led++;
    if (led == 8) {
      for(int x = 0; x <= 10; x++){
        int delayTime = 30;
        for (int y = 2; y < 8; y++) {
          digitalWrite(y, LOW);
          delay(delayTime);
        }
        for (int y = 8; y >= 2; y--) {
          digitalWrite(y, HIGH);
          delay(delayTime);
        }
        for (int y = 8; y >= 2; y--) {
          digitalWrite(y, LOW);
          delay(delayTime);
        }
        for (int y = 2; y < 8; y++) {
          digitalWrite(y, HIGH);
          delay(delayTime);
        }  
      }
    }
  }
  
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }
    led = 2;
    timeOfLight = currentTime;
  }
  prevSwitchState = switchState;
}
