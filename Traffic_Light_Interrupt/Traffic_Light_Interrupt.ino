volatile bool redState = false;
volatile bool greenState = false;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), toggleRed, RISING);
  attachInterrupt(digitalPinToInterrupt(3), toggleGreen, RISING);
}

void toggleRed() {
  redState = !redState;
}

void toggleGreen() {
  greenState = !greenState;
}

void trafficLightReset(int lights[]){
  for (int x = 0; x <= 3; x++){
    digitalWrite( lights[x], LOW );
  }
}

void trafficLight(int lights[], int light, int duration){
  trafficLightReset(lights);
  digitalWrite(light, HIGH);
  delay(duration);
}

void loop() {
  int lightRed = 6;
  int lightYellow = 5;
  int lightGreen = 4;
  int lights[3] = {4,5,6};

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
