int echopin = 11;
int trigpin = 12;
int m4=4;
int m3=5;
int m2=6;
int m1=7;
long duration;
int distance;
void setup() {
Serial.begin(9600);
pinMode(echopin, INPUT);
pinMode(trigpin, OUTPUT);
pinMode(m1,OUTPUT);

pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
}

void loop() 
{
 dist();
 if(distance<40)
 {
  forward();
 } 
 
 else
  {
    check();
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
  delay(10);
  delay(10);
  
  }

  void forward()
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    Serial.println("Forward");
    Serial.println(distance);
    dist();
  }

  void backward()
  {
    digitalWrite(m2, HIGH);
    digitalWrite(m1, LOW);
    digitalWrite(m4, LOW);
    digitalWrite(m3, HIGH);
    Serial.println(distance);
    dist();
  }

  void left()
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    Serial.println("Left");
    Serial.println(distance);
    dist();
  }

  void right()
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    Serial.println("Right");
    Serial.println(distance);
    dist();
  }

  void stop()
  {
    digitalWrite(m2, LOW);
    digitalWrite(m1, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    Serial.println("Stop");
    dist();
  }
  void check()
  {
    stop();
    delay(500);
    if(distance>70)
    {
      do
      {
        left();
        delay(100);

      }
      while(distance>60);
    } 
      else 
        {
          do 
          {
            right();
            delay(100);

          }
          while (distance>60);
        } 
       
  }