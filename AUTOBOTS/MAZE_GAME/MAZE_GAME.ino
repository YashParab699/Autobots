#include<SoftwareSerial.h>

SoftwareSerial Bluetooth(2,3);
int Left=8;
int Up=9;
int Down=10;
int Right=11;


void setup() 
{
  pinMode(Left, INPUT);
  pinMode(Up, INPUT);
  pinMode(Down, INPUT);
  pinMode(Right, INPUT);

  Serial.begin(9600);
  Bluetooth.begin(9600);

}

void loop() {
  int s_v1=digitalRead(Left);
  int s_v2=digitalRead(Up);
  int s_v3=digitalRead(Down);
  int s_v4=digitalRead(Right);

  if (s_v4 == HIGH) {
    Bluetooth.println("a");
    delay(500);
  }
  else if (s_v3==HIGH) {
  Bluetooth.print("b");
  delay(500);
  }
  else if (s_v2==HIGH) {
  Bluetooth.print("c");
  delay(500);
  }
  else if (s_v1==HIGH) {
  Bluetooth.print("d");
  delay(500);
  }
  else 
  {
  Bluetooth.print("");
  delay(500);
  }
  Serial.print(s_v1);
  Serial.print("\t");
  Serial.print(s_v2);
  Serial.print("\t");
  Serial.print(s_v3);
  Serial.print("\t");
  Serial.println(s_v4);

  // Bluetooth.print(s_v1);
  // Bluetooth.print("\t");
  // Bluetooth.print(s_v2);
  // Bluetooth.print("\t");
  // Bluetooth.print(s_v3);
  // Bluetooth.print("\t");
  // Bluetooth.print(s_v4);
}
