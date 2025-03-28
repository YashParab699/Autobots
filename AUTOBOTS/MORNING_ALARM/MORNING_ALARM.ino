#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(12,11);
int led = 4;
int buzzer = 3;
int ldr = A0;

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int val = analogRead(ldr);
  Serial.println(val);
  Bluetooth.println(val);
  delay(1000);
 if(val<=50)
 {
  Serial.println("Wake Up");
  digitalWrite(led, LOW);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
 }
 else if(val>200)
 {
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, LOW);
  delay(500);
  digitalWrite(led, LOW);
 }
 else 
 {
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
 }
}
