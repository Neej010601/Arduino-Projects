#include <Arduino.h>
int val;
void setup() {
  Serial.begin(9600);  //for terminal
  pinMode(A1, INPUT); //pin mode
}

void loop() {
  val = analogRead(A1); //getting the voltage reading from the temperature sensor
  float mV = (val/1024.0)*5000; //convert the val in mV 
  float cel = mV/10; //mV to cel
//  uncomment the next line if you want data in far
//  float far = (cel*9)/5+32;   
  Serial.print("Temperaure= ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println("");
  delay(200);
}
