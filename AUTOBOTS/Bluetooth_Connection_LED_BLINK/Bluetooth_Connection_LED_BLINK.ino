#include <SoftwareSerial.h>
char x;

int Led =13;
SoftwareSerial Bluetooth(2,3);
void setup() {
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() 
{
  if(Bluetooth.available()>0)
  {
    x=Bluetooth.read();
    if(x=='1')
    {
      digitalWrite(Led, HIGH);
    }
    if(x=='0')
    {
      digitalWrite(Led, LOW);
    }
  }


}
