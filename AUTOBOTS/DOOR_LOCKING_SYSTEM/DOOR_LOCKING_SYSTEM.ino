#include <Servo.h>
#include <Keypad.h>
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);
char BT_input;
Servo myservo;
int pos;
int Servo = 0;
// const byte ROWS =4;
// const byte COLS =4;
// char keys[ROWS][COLS]=
// {
//   {'1','2','3','A'},
//   {'4','5','6','B'},
//   {'7','8','9','C'},
//   {'*','0','#','D'}
// };
// byte  rowPins[ROWS]= {2,3,4,5};
// byte  colPins[COLS]= {6,7,8,9};
// Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
String password ="1234";
String input;

void setup() {
Serial.begin(9600);
Bluetooth.begin(9600);
myservo.attach(9);
}

void loop() 
{
  // char Key = keypad.getKey();
  // if(Key)
  // {
  //   if(input.length()<4)
  //   {
  //     input+=Key;
  //     Serial.print(Key);
  //   }
  // }
 if(Bluetooth.available()>0)
  {
    BT_input=Bluetooth.read();
      if( BT_input=='y')
      {
        Serial.println("Correct Password");
        Bluetooth.println("Correct Password");
        for (pos=180; pos>=0; pos-=25) 
        {
         myservo.write(pos);
         delay(5);
        }
        delay(2000);
        for (pos=0; pos<=180; pos+=25) 
        {
          myservo.write(pos);
          delay(5);
        }
      }
      else 
      {
        Serial.println("Incorrect Password \n Try Again");
        Bluetooth.println("Incorrect Password \n Try Again");
      }
  }
}
