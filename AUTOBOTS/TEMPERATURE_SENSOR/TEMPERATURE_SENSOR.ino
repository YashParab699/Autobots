#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
int ts=A0;
int red=10;
int green=9;
int blue=8;

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);
  pinMode(ts, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  float sensor_val=analogRead(ts);
  sensor_val=(sensor_val*500)/1023;
  Serial.println(sensor_val);
  Bluetooth.println(sensor_val);
  delay(500);
  if (sensor_val>=32) 
  {
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 255);
    Serial.println("HIGH TEMPERATURE");
  }
  if (sensor_val<32 && sensor_val>24) 
  {
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 255);
    Serial.println("NORMAL TEMPERATURE");
  }
  if (sensor_val<=24) 
  {
    analogWrite(red, 255);
    analogWrite(green, 255);
    analogWrite(blue, 0);
    Serial.println("LOW TEMPERATURE");
  }
}

