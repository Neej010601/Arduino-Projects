#include <Arduino.h>

#include <SHT1x-ESP.h>
SHT1x sht1x (12, 13);

void setup() {
  Serial.begin(9600);
  Serial.print("Starting Up..");
}

void loop() {
  float temp_c = sht1x.readTemperatureC();
  float temp_f = sht1x.readTemperatureF();
  float humidity = sht1x.readHumidity();

  Serial.print("Temperature in celcius is ");
  Serial.print(temp_c);
  Serial.print("/");
  Serial.print("Temperature in farehnite is ");
  Serial.print(temp_f);
  Serial.print("/");
  Serial.print("Humidity is ");
  Serial.print(humidity);
  Serial.println("");
}
