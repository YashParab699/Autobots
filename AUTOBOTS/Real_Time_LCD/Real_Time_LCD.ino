  #include <SoftwareSerial.h>
  #include<LiquidCrystal.h>
  int rs = 4,en = 5, d4= 6, d5= 7, d6=8 ,d7=9 ;
  LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
  SoftwareSerial Bluetooth(2,3);
  // String input;
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
    // lcd.setCursor(0, 0);
    // lcd.write("uint8_t");
    // delay(1000);
    // lcd.clear();


    if(Bluetooth.available())
    {
      String input=Bluetooth.readString();
      Serial.println(input);
      lcd.print(input);
      
      if(input=="1")
      {
        lcd.clear();
        Serial.print("aaya aaya");
        
      }
    }
    // delay(1500);
    // lcd.clear();
  }
