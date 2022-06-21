#include <Arduino.h>
void setup() {
  Serial.begin(9600);
}

void loop() {
  int x = Serial.read();
   if (x == 'a') {
    Serial.println("Apple.");
  }
   else if (x == 'b') {
    Serial.println("Ball.");
  }
   else if (x == 'c') {
    Serial.println("Cat.");
  }
   else if (x == 'd') {
    Serial.println("Dog.");
  }
   else if (x == 'e') {
    Serial.println("Elephant.");
  }
   else if (x == 'f') {
    Serial.println("Fish.");
  }
   else if (x == 'g') {
    Serial.println("Grapes.");
  } 
  else if (x == 'h') {
    Serial.println("Hen.");
  } 
  else if (x == 'i') {
    Serial.println("Ice.");
  } 
  else if (x == 'j') {
    Serial.println("Jar.");
  } 
  else if (x == 'k') {
    Serial.println("King.");
  } 
  else if (x == 'l') {
    Serial.println("Lambda.");
  } 
  else if (x == 'm') {
    Serial.println("MDB.");
  } 
}
