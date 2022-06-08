#include <LiquidCrystal.h> //Library for LCD Display 

//naming of pins
int led1 = 6;
int led2 = 5;
int led3 = 4;
int led4 = 3;
int led5 = 2;
int led6 = 7;
int led7 = 1;
int led8 = 0;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

//setup the pinmodes
void setup() {
  lcd.begin(16, 2); //Showing that we use 16*2 LCD
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
}

void loop() {
  int LDR = analogRead(A2); //LDR will send the data as analog signal.
  int temp = map(LDR, 0,1023,0,600); //map the data that 0 refers to 0 and 1023 refers to 600. map(value, fromLow, fromHigh, toLow, toHigh)
  lcd.setCursor(0, 0); //LCD(bit, line) means 0 shows first bit in 0th line means top line.
  lcd.print("Fetching Data ADC: ");
  lcd.setCursor(0, 1); .//LCD(bit, line) means 0 shows first bit in 1st line means bottom line.
  lcd.print(temp);
  delay(10);
  lcd.clear(); //for clear the LCD
  
//for conditions of operations
  if (LDR == 0) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  if (LDR > 0) {
    digitalWrite(led1, HIGH);
  }
  if (LDR > 32) {
    digitalWrite(led2, HIGH);
  }
  if (LDR > 64) {
    digitalWrite(led3, HIGH);
  }
  if (LDR > 96) {
    digitalWrite(led4, HIGH);
  }
  if (LDR > 128) {
    digitalWrite(led5, HIGH);
  }
  if (LDR > 160) {
    digitalWrite(led6, HIGH);
  }
  if (LDR > 192) {
    digitalWrite(led7, HIGH);
  }
  if (LDR > 224) {
    digitalWrite(led8, HIGH);
  }
  if (LDR < 0) {
    digitalWrite(led1, LOW);
  }
  if (LDR < 32) {
    digitalWrite(led2, LOW);
  }
  if (LDR < 64) {
    digitalWrite(led3, LOW);
  }
  if (LDR < 96) {
    digitalWrite(led4, LOW);
  }
  if (LDR < 128) {
    digitalWrite(led5, LOW);
  }
  if (LDR < 160) {
    digitalWrite(led6, LOW);
  }
  if (LDR < 192) {
    digitalWrite(led7, LOW);
  }
  if (LDR < 224) {
    digitalWrite(led8, LOW);
  }
}
