volatile bool redState = false;
volatile bool greenState = false;

namespace canttouchthis {
  typedef struct {
    int lightPins[10];
    int numberOfLights;
  } LightDef;
}


//resets all pins in lights
void trafficLightReset(canttouchthis::LightDef lights) {
  for (int x = 0; x <= lights.numberOfLights; x++) {
    digitalWrite(lights.lightPins[x], LOW);
  }
}

void trafficLight(canttouchthis::LightDef lights, int light, int duration) {
  trafficLightReset(lights);
  digitalWrite(light, HIGH);
  delay(duration);
}

//controls state of red light
void toggleRed() {
  redState = !redState;
}

//controls state of green light
void toggleGreen() {
  greenState = !greenState;
}

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), toggleRed, RISING);   //Uses pins 2 and 3 as interrupt pins
  attachInterrupt(digitalPinToInterrupt(3), toggleGreen, RISING);
}

void loop() {
  int lightRed = 6;
  int lightYellow = 5;
  int lightGreen = 4;
  canttouchthis::LightDef lights;
  lights.lightPins[0] = lightRed;
  lights.lightPins[1] = lightYellow;
  lights.lightPins[2] = lightGreen;
  lights.numberOfLights = 3;

  if (redState) {
    trafficLight(lights, lightRed, 100);
  }
  else if (greenState) {
    trafficLight(lights, lightGreen, 100);
  }
  else {
    trafficLight(lights, lightGreen, 2000);
    trafficLight(lights, lightYellow, 500);
    trafficLight(lights, lightRed, 2000);
  }
}
