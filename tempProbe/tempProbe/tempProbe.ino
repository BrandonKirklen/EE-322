#include <Wire.h>
int tempAddress = 72; //1001000 in dec

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void initializeChip(int chipAddress){
  //Begin Session
  Wire.beginTransmission(chipAddress);
  //Ask for the register
  Wire.write(0);
  // Complete transmission
  Wire.endTransmission();
  //Read temp
  Wire.requestFrom(chipAddress, 1);
}

void serialPrint(int C, int F){
  Serial.print(C);
  Serial.print("C ");
  Serial.print(F);
  Serial.println("F ");
}


void loop() {
  int tempC, tempF;
  initializeChip(tempAddress);
 
  while(Wire.available() == 1){
    tempC = Wire.read();
  }

  tempF = round(tempC*9.0/5.0 + 32.0);

  serialPrint(tempC, tempF);
  delay(500);
}
