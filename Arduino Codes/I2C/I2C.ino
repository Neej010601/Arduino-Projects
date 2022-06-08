#include <Wire.h> // this library use to communicate with I2C
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2); //Setup of 16*2 LCD with I2C. 0x20 is the address for I2C (inbuilt)
void setup()
{
  lcd.init();  //initialize the lcd                    
  lcd.backlight();
  lcd.setCursor(0,0); // 0th (1st) bit of 0th (1st) line 
  lcd.print("Hello, Neej!");
  delay(500);
  lcd.clear(); //clear the lcd text
}


void loop()
{
//  Operating code
  lcd.setCursor(3,0);
  lcd.print("Welcome to Jumanji :)");
  for (int pos = 0; pos<25 ; pos ++){  //with the part we are scrolling the text because it is more than 16 words
  lcd.scrollDisplayLeft();
  delay(150);   
  }
  lcd.clear(); //clear the lcd
}
