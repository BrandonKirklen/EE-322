// named constant for the pin the sensor is connected to
const int sensorPin = A0;
// room temperature in Celcius
const float baselineTemp = 28.0;
bool print = false;

void setup() {
  // open a serial connection to display values
  Serial.begin(9600);
  pinMode(1, INPUT);
  // set the LED pins as outputs
  // the for() loop saves some extra coding
//  for (int pinNumber = 8; pinNumber <= 10; pinNumber++) {
//    pinMode(pinNumber, OUTPUT);
//    digitalWrite(pinNumber, LOW);
//  }
}

void loop() {
  // read the value on AnalogIn pin 0
  // and store it in a variable
  int sensorVal = analogRead(sensorPin);
  int ledRed = 10;
  int ledYellow = 9;
  int ledGreen = 8;
  int switchState = 0;
  switchState = digitalRead(1);

float voltage = (sensorVal / 1024.0) * 5.0;

if( switchState == HIGH ){
  print = !print;
}

if( print ){
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltage);
}

  // convert the voltage to temperature in degrees C
  // the sensor changes 10 mV per degree
  // the datasheet says there's a 500 mV offset
  // ((volatge - 500mV) times 100)
//  Serial.print(", degrees C: ");
//  float temperature = (voltage - .5) * 100;
//  Serial.println(temperature);

  // if the current temperature is lower than the baseline
  // turn off all LEDs
//  if (temperature < baselineTemp + 2) {
//    digitalWrite(ledRed, LOW);
//    digitalWrite(ledYellow, LOW);
//    digitalWrite(ledGreen, LOW);
//  } // if the temperature rises 2-4 degrees, turn an LED on
//  else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
//    digitalWrite(ledRed, HIGH);
//    digitalWrite(ledYellow, LOW);
//    digitalWrite(ledGreen, LOW);
//  } // if the temperature rises 4-6 degrees, turn a second LED on
//  else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
//    digitalWrite(ledRed, HIGH);
//    digitalWrite(ledYellow, HIGH);
//    digitalWrite(ledGreen, LOW);
//  } // if the temperature rises more than 6 degrees, turn all LEDs on
//  else if (temperature >= baselineTemp + 6) {
//    digitalWrite(ledRed, HIGH);
//    digitalWrite(ledYellow, HIGH);
//    digitalWrite(ledGreen, HIGH);
//  }
  delay(1);
}
