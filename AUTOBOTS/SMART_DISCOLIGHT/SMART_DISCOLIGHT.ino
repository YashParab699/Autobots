#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(4,5);
#define NUM_LED 10
#define LED_PIN 2
Adafruit_NeoPixel strip=Adafruit_NeoPixel(NUM_LED,LED_PIN,NEO_GRB+NEO_KHZ800);
char Bt_input;
int delayVal = 10;
int red = 0;
int green = 0;
int blue = 0;

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  strip.begin();

}

void loop() 
{
  if(Bluetooth.available()>0)
  {
    Bt_input=Bluetooth.read();
    Serial.println(Bt_input);
    if(Bt_input=='R')
    {
      Serial.println("Red");
        for(int i=0;i<10;i++)
        {
          red=255;green=0;blue=0;
          strip.setPixelColor(i,red,green,blue);
          strip.show();
          delay(50);
        }
          strip.clear();
    }
    if(Bt_input=='G')
    {
      Serial.println("Green");
        for(int i=0;i<10;i++)
        {
          green=255;red=0;blue=0;
          strip.setPixelColor(i,red,green,blue);
          strip.show();
          delay(50);
        }
          strip.clear();
    }
    if(Bt_input=='B')
    {
      Serial.println("Blue");
        for(int i=0;i<10;i++)
        {
          blue=255;green=0;red=0;
          strip.setPixelColor(i,red,green,blue);
          strip.show();
          delay(50);
        }
          strip.clear();
    }
    if(Bt_input=='Y')
    {
      Serial.println("Yellow");
        for(int i=0;i<10;i++)
        {
          red=255;green=255;blue=0;
          strip.setPixelColor(i,red,green,blue);
          strip.show();
          delay(50);
        }
          strip.clear();
    }
    if(Bt_input=='C')
    {
      Serial.println("Cyan");
        for(int i=0;i<10;i++)
        {
          red=0;green=255;blue=255;
          strip.setPixelColor(i,red,green,blue);
          strip.show();
          delay(50);
        }
          strip.clear();
    }
    if(Bt_input=='P')
    {
      Serial.println("Purple");
        for(int i=0;i<10;i++)
        {
          red=255;green=0;blue=255;
          strip.setPixelColor(i,red,green,blue);
          strip.show();
          delay(50);
        }
          strip.clear();
    }
    if(Bt_input=='W')
    {
      Serial.println("White");
        for(int i=0;i<10;i++)
        {
          red=255;green=255;blue=255;
          strip.setPixelColor(i,red,green,blue);
          strip.show();
          delay(50);
        }
          strip.clear();
    }
    if(Bt_input=='O')
    {
      Serial.println("OFF");
        for(int i=0;i<10;i++)
        {
          red=0;green=0;blue=0;
          strip.setPixelColor(i,red,green,blue);
          strip.show();
          delay(50);
        }
          strip.clear();
    }
  }
}
