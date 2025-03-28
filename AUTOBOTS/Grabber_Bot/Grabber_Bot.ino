  #include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial Bluetooth(3,2);
char BT_input;
Servo myservo;
int pos =0;
int m4=8;//M1-FORWARDS
int m3=9;//M1-BACWARDS
int m2=11;//M2-BACKWARDS
int m1=10;//M2-FORWARDS

void setup() {

  Bluetooth.begin(9600);
  Serial.begin(9600);
pinMode(m1, OUTPUT);
pinMode(m2, OUTPUT);
pinMode(m3, OUTPUT);
pinMode(m4, OUTPUT);
myservo.attach(7);

}

void loop() {
 
if (Bluetooth.available()>0){
BT_input=Bluetooth.read();
Serial.println(BT_input);
if(BT_input=='B'){        //FORWARD 
 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
   delay(10);
}
else if(BT_input=='F'){     //BACKWARD
 digitalWrite(m1, LOW);
 digitalWrite(m2, HIGH);
 digitalWrite(m3, LOW);
 digitalWrite(m4, HIGH);
 delay(10);
}

else if(BT_input=='R'){     //LEFT

 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, LOW);
 digitalWrite(m4, HIGH);
  delay(10);
}
else if(BT_input=='L'){     //RIGHT
 digitalWrite(m1, LOW); 
 digitalWrite(m2, HIGH);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
 delay(10);
}
else if (BT_input=='S') {     //STOP
digitalWrite(m1, LOW); 
 digitalWrite(m2, LOW);
 digitalWrite(m3, LOW);
 digitalWrite(m4, LOW);
 delay(10);
}

else if(BT_input=='G') {      //GRAB
  myservo.write(90);
}
else if(BT_input=='LE') {     //LEAVE
  myservo.write(0);
}
}
}