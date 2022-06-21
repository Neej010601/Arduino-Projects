#include <Arduino.h>

String voice;
void setup() {
  // for bluetooth we use serial.begin
  Serial.begin(9600);
  //  Pin modes
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  //  get the data from bluetooth
  while(Serial.available()) {
    delay(3);
   //read the data and add in voice
    char c = Serial.read();
    voice += c;
  }
  //  Operating Code
    if (voice.length()){
      if (voice == "lamp on") {
        digitalWrite(11, HIGH);
      }
      else if (voice == "lamp off") {
        digitalWrite(11, LOW);
      }
      else if (voice == "night lamp on") {
        digitalWrite(10, HIGH);
      }
      else if (voice == "night lamp off") {
        digitalWrite(10, LOW);
      }
      else if (voice == "fan on") {
        digitalWrite(5, HIGH);
      }
      else if (voice == "fan off") {
        digitalWrite(5, LOW);
      }
      else if (voice == "all on") {
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(5, HIGH);
      }
      else if (voice == "all of") {
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        digitalWrite(5, LOW);
      }
      voice = ""; //Clear the voice
    }
  }
