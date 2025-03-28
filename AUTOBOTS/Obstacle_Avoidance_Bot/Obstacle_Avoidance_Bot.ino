#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
int echopin = 13;
int trigpin = 12;
int m4=4;
int m3=5;
int m2=6;
int m1=7;
long duration;
int distance;
int BT_input;
void setup() {
  // put your setup code here, to run once:
Bluetooth.begin(9600);
Serial.begin(9600);
pinMode(echopin, INPUT);
pinMode(trigpin, OUTPUT);
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
}

void loop() {
 dist();
 forward();
 if(distance<=15)
 {
  stop();
  delay(100);
  backward();
  delay(300);
  left()
  delay(300);
 }
 
  
}
  void dist()
  {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration= pulseIn(echopin,HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  delay(100);
  Bluetooth.println(distance);
  delay(100);
  
  }

void forward()
  {
    digitalWrite(m2, LOW);
    digitalWrite(m1, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    Serial.println("Forward");
  }

  void backward()
  {
    digitalWrite(m2, HIGH);
    digitalWrite(m1, LOW);
    digitalWrite(m4, LOW);
    digitalWrite(m3, HIGH);
  }

  void right()
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  void left()
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  void stop()
  {
    digitalWrite(m2, LOW);
    digitalWrite(m1, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }