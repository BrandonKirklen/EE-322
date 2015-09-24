void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void trafficLight(int light, int duration){
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(light, HIGH);
  delay(duration);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightRed = 6;
  int lightYellow = 5;
  int lightGreen = 4;
  int allStop = digitalRead(2);
  int allGo = digitalRead(3);

  if ( allStop == HIGH && allGo == HIGH ){
    trafficLight(lightYellow, 5000);
  }
  else if ( allStop == HIGH ){
    trafficLight(lightRed, 5000);
  }
  else if ( allGo == HIGH ){
    trafficLight(lightGreen, 5000);
  }
  else if (allStop != HIGH && allGo != HIGH ){
    trafficLight(lightRed, 1000);
    trafficLight(lightYellow, 500);
    trafficLight(lightGreen, 1000); 
  }
}
