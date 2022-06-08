void setup() {
//  Serial.begin(9600); //This is for Terminal
// setups of pins
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}

//loop for working
void loop() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(8, HIGH);
  delay(200);
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(3, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
  digitalWrite(12, LOW);
  delay(200);
  digitalWrite(10, LOW);
  delay(200);
  digitalWrite(8, LOW);
  delay(200);
  digitalWrite(5, LOW);
  delay(200);
  digitalWrite(3, LOW);
  delay(400);
}
