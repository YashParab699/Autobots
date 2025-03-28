#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
char x;
int Button=8;
void setup() 
{
  pinMode(Button, INPUT_PULLUP);  
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() 
{
  int v = digitalRead(Button);
  Serial.println(v);
  delay(1000);
  Bluetooth.write(v);
    
}
