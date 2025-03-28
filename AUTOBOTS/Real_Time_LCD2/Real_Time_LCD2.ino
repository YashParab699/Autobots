#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
int rs = 4,en = 5, d4= 6, d5= 7, d6=8 ,d7=9 ;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);SoftwareSerial Bluetooth(2,3);
String input_data;
String date;
void setup() 
{
  Serial.begin(9600);
  Bluetooth.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.clear();
}

void loop() 
{
 

  if(Bluetooth.available())
  {
    byte FCI = input_data.indexOf(',');
    byte SCI = input_data.indexOf(',',FCI+1);
    date = input_data.substring(0,FCI);
    String time=input_data.substring(FCI+1,SCI);
    Serial.println(input_data);
    lcd.clear();
    lcd.print("Date :");
    lcd.print(date);
    Serial.println(date);
    lcd.setCursor(0,1);
    lcd.print("time");
    lcd.print(time);
    Serial.println(time);
  }
    
}
