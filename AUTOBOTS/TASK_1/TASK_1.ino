#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
int time = 0;
int m1=7;
int m2=6;
int m3=5;
int m4=4;
String input ;
void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  if(Bluetooth.available()>0)
  {
    input=Bluetooth.readString();
    time=input.toInt();
    time=time*1000;
    Serial.println(input);
    Serial.println(time);
    forward();
    delay(time);
    stop();
  }

}
void forward()
{
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}
void stop()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
