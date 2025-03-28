#include<SoftwareSerial.h>

char BT_input;
SoftwareSerial Bluetooth(2,3);
void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  if(Bluetooth.available())
  {
    BT_input=Bluetooth.read();
    Serial.write(BT_input);
  }
  if(Serial.available())
  {
    BT_input=Serial.read();
    Bluetooth.write(BT_input);
  }
}
