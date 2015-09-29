volatile bool redState = false;
volatile bool greenState = false;

struct LightDef{
  int lightPins[10];
  int numberOfLights;
};
 
void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
 
  attachInterrupt(digitalPinToInterrupt(2), toggleRed, RISING);   //Uses pins 2 and 3 as interrupt pins
  attachInterrupt(digitalPinToInterrupt(3), toggleGreen, RISING);
}
 
//controls state of red light
void toggleRed() {
  redState = !redState;
}
 
//controls state of green light
void toggleGreen() {
  greenState = !greenState;
}
 
//resets all pins in lights
void trafficLightReset(struct LightDef lights){
  for (int x = 0; x <= lights.numberOfLights; x++){
    digitalWrite(lights.lightPins[x], LOW);
  }
}
 
void trafficLight(struct LightDef lights, int light, int duration){
  trafficLightReset(lights);
  digitalWrite(light, HIGH);
  delay(duration);
}
 
void loop() {
  int lightRed = 6;
  int lightYellow = 5;
  int lightGreen = 4;
  struct LightDef lights;
  lights.lightPins[0] = 4;
  lights.lightPins[1] = 5;
  lights.lightPins[2] = 6;
  lights.numberOfLights = 3;
 
  if (redState){
    trafficLight(lights, lightRed, 1000);
  }
  else if(greenState){
    trafficLight(lights, lightGreen, 1000);
  }
  else{
    trafficLight(lights, lightGreen, 2000);
    trafficLight(lights, lightYellow, 500);
    trafficLight(lights, lightRed, 2000);
  }
}
