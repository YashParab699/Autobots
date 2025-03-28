#include<SoftwareSerial.h>

int Led1=4;
int Led2=9;
int Led3=10;
char BT_input;
SoftwareSerial Bluetooth(12,11);
void setup() {
  pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  if(Bluetooth.available()>0)
  {
    BT_input=Bluetooth.read();
    
    Serial.write(BT_input);
    if(BT_input=='R')
    {
      digitalWrite(Led1,HIGH);
      digitalWrite(Led2,LOW);
      digitalWrite(Led3,LOW);
    }

    else if(BT_input=='Y')
    {
      digitalWrite(Led1,LOW);
      digitalWrite(Led2,HIGH);
      digitalWrite(Led3,LOW);
    }

    else if(BT_input=='G')
    {
      digitalWrite(Led1,LOW);
      digitalWrite(Led2,LOW);
      digitalWrite(Led3,HIGH);
    }
  }
  if(Serial.available())
  {
    BT_input=Serial.read();
    Bluetooth.write(BT_input);

    if(BT_input=='R')
    {
      digitalWrite(Led1,HIGH);
      digitalWrite(Led2,LOW);
      digitalWrite(Led3,LOW);
    }

    else if(BT_input=='Y')
    {
      digitalWrite(Led1,LOW);
      digitalWrite(Led2,HIGH);
      digitalWrite(Led3,LOW);
    }

    else if(BT_input=='G')
    {
      digitalWrite(Led1,LOW);
      digitalWrite(Led2,LOW);
      digitalWrite(Led3,HIGH);
    }
  }
}
