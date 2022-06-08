String text;
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
//read the data and add in text
    char c = Serial.read();
    text += c;
  }

    if (text.length()){
      if (text == "lamp on") {
        digitalWrite(11, HIGH);
      }
      else if (text == "lamp off") {
        digitalWrite(11, LOW);
      }
      else if (text == "night lamp on") {
        digitalWrite(10, HIGH);
      }
      else if (text == "night lamp off") {
        digitalWrite(10, LOW);
      }
      else if (text == "fan on") {
        digitalWrite(5, HIGH);
      }
      else if (text == "fan off") {
        digitalWrite(5, LOW);
      }
      else if (text == "all on") {
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(5, HIGH);
      }
      else if (text == "all off") {
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        digitalWrite(5, LOW);
      }
      text = ""; //Clear the text
    }
  }
