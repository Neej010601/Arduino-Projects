#include <Arduino.h>

#include <LiquidCrystal.h> //for 16*2 LCD
#include <Servo.h> //for servo motor
#include <Keypad.h> //for keypad
Servo myservo;
int pos = 0; //position of servo motor

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const byte rows=4; //4 rows
const byte cols=3; //3 columns
// Structure of the keypad
char key[rows][cols]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

byte rowPins[rows] = {0, 1, 2, 3}; //pins connected with rows
byte colPins[cols] = {4, 5, 6}; //pins connected with column
Keypad keypad = Keypad(makeKeymap(key), rowPins, colPins, rows, cols);
char*password = "0123"; //password set by us
int currentposition = 0; //initially door will be closed


void setup() {
  displayscreen();
  Serial.begin(9600);
  myservo.attach(12); //motor attaced on pin
  lcd.begin(16, 2);
}

void loop() {
  if (currentposition == 0)
  {
    displayscreen();
  }
int l ;
char code=keypad.getKey(); //getting the input from us
if(code!=NO_KEY)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password:");
    lcd.setCursor(7, 1);
    lcd.print(" ");
    lcd.setCursor(7, 1);
    for(l=0;l<=currentposition;++l)
    {
    lcd.print("*");
//keypress();
}
 
if (code==password[currentposition])
{
++currentposition;
if(currentposition==4)
{
 
unlockdoor();
currentposition=0;
 
}
 
}

 
else
{
incorrect();
currentposition=0;
 
}
}
}
 

//open the door

void unlockdoor()
{
  delay(500);
  lcd.setCursor(0, 0);
  lcd.println(" ");
  lcd.setCursor(1, 0);
  lcd.print("Access Granted");
  lcd.setCursor(4, 1);
  lcd.print("Welcome");
  lcd.setCursor(15, 1);
  lcd.println(" ");
  lcd.setCursor(16, 1);
  lcd.println(" ");
  lcd.setCursor(14, 1);
  lcd.println(" ");
  lcd.setCursor(13, 1);
  lcd.println(" ");

  for (pos = 180; pos >= 0; pos -= 5) // open the door
  {
    myservo.write(pos);
    delay(10);
  }
  delay(2000);

  delay(1000);
  counterbeep();

  delay(1000);
  for (pos = 0; pos <= 180; pos += 5) // close the door
  { //in steps of 1 degree
    myservo.write(pos);
    delay(15);
    currentposition=0;
    lcd.clear();
    displayscreen();
  }
}

//wrong code
void incorrect()
{
delay(500);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("CODE");
lcd.setCursor(6,0);
lcd.print("INCORRECT");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(4,1);
lcd.println("GET AWAY!!!");
 
lcd.setCursor(13,1);
lcd.println(" ");
Serial.println("CODE INCORRECT YOU ARE UNAUTHORIZED");
delay(3000);
lcd.clear();
displayscreen();
}
//clear the screen
void clearscreen()
{
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(0,1);
lcd.println(" ");
lcd.setCursor(0,2);
lcd.println(" ");
lcd.setCursor(0,3);
lcd.println(" ");
}

//display function
void displayscreen()
{
 
lcd.setCursor(0,0);
lcd.println("*ENTER THE CODE*");
lcd.setCursor(1 ,1);
 
lcd.println("TO OPEN DOOR!!");
}


 
//countdown
void counterbeep()
{
delay(1200);
 
 
lcd.clear();
 
lcd.setCursor(2,15);
lcd.println(" ");
lcd.setCursor(2,14);
lcd.println(" ");
lcd.setCursor(2,0);
delay(200);
lcd.println("GET IN WITHIN:::");
 
lcd.setCursor(4,1);
lcd.print("5");
delay(200);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
delay(1000);
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1); //2
lcd.print("4");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
delay(1000);

lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1); 
lcd.print("3");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
delay(1000);

lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1); 
lcd.print("2");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
delay(1000);

lcd.setCursor(4,1);
lcd.print("1");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN::");

delay(1000);
delay(40);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("RE-LOCKING");
delay(500);
lcd.setCursor(12,0);
lcd.print(".");
delay(500);
lcd.setCursor(13,0);
lcd.print(".");
delay(500);
lcd.setCursor(14,0);
lcd.print(".");
delay(400);
lcd.clear();
lcd.setCursor(4,0);
lcd.print("LOCKED!");
delay(440);
}
