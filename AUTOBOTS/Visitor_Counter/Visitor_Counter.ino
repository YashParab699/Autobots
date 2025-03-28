#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
SoftwareSerial Bluetooth(2,3);
int PIRsensor = 13;
int rs = ,en = , d4= , d5= , d6= ,d7= ;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int count=0;
void setup() 
{
  Serial.begin(9600);
  Bluetooth.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Visitor Counter");
  pinMode(PIRsensor, INPUT);
}

void loop() 
{
  int sensor_value=digitalRead(PIRsensor);
  
  if(sensor_value==1)
  {
    count+=1;
    Bluetooth.println(count);
    lcd.setCursor(0,1);
    lcd.print("Count-");
    Serial.println(count);
  }
  delay(1000);
}
