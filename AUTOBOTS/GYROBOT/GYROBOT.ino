#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
char data=0;
int m4=4;
int m3=5;
int m2=6;
int m1=7;
void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
Serial.begin(9600);
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Bluetooth.available()>0)
{
  data=Bluetooth.read();
  Serial.println(data);

  if(data=='F'){
    digitalWrite(m2, LOW);
    digitalWrite(m1, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  if(data=='B'){
    digitalWrite(m2, HIGH);
    digitalWrite(m1, LOW);
    digitalWrite(m4, LOW);
    digitalWrite(m3, HIGH);
  }

  if(data=='L'){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  if(data=='R'){
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  if(data=='S'){
    digitalWrite(m2, LOW);
    digitalWrite(m1, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
}
}



