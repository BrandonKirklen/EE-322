void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void trafficLightReset(int lights[]){
  for (int x = 0; x <= 3 ; x++){
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
  int allStop = digitalRead(2);
  int allGo = digitalRead(3);

  if ( allStop == HIGH && allGo == HIGH ){
    trafficLight(lights, lightYellow, 5000);
  }
  else if ( allStop == HIGH ){
    trafficLight(lights, lightRed, 5000);
  }
  else if ( allGo == HIGH ){
    trafficLight(lights, lightGreen, 5000);
  }
  else{
    trafficLight(lights, lightGreen, 1000);
    trafficLight(lights, lightYellow, 500);
    trafficLight(lights, lightRed, 1000); 
  }
}
