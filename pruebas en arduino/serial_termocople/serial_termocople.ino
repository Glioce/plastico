// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"

int thermoDO = 3;
int thermoCS = 4;
int thermoCLK = 5;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 6;
int gndPin = 7;
  
void setup() {
  Serial.begin(9600);
  // use Arduino pins 
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  
  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
  
   Serial.print("C = "); 
   Serial.print(thermocouple.readCelsius());
   Serial.print("\tF = ");
   Serial.println(thermocouple.readFahrenheit());
 
   delay(500);
}
