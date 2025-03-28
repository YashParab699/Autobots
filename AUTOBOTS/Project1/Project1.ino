#include<SoftwareSerial.h>
char x;

int red =8;
int blue =9;
int green =10;
SoftwareSerial Bluetooth(4,5);
void setup() 
{
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() 
{

  if(Bluetooth.available()>0)
  {
    x=Bluetooth.read();
    Serial.println(x);
    if(x=='1')
    {
      digitalWrite(blue, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
    }

    if(x=='2')
    {
      digitalWrite(blue, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(red, HIGH);
    }

    if(x=='3')
    {
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      digitalWrite(red, HIGH);
    }
    
    if(x=='9')
    {
      digitalWrite(blue, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(red, HIGH);
    }
    Serial.write(x);
    Bluetooth.write(x);
  }
}
