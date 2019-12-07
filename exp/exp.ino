#include <Servo.h>
Servo myservo;
void setup() {
  pinMode(A0,OUTPUT);
  pinMode(12,OUTPUT); 
  pinMode(13,INPUT);
  pinMode(2,OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
}
int distance,duration,p,r;
void loop() {
    digitalWrite(12,HIGH);
    delay(10);
    digitalWrite(12,LOW);
    duration=pulseIn(13,HIGH)/2;delay(1000);
    distance = duration/29;
    Serial.println(distance);
    if(distance<=5)
    {
      digitalWrite(2,1);

      for(p=0;p<=180;p++)
      {
       myservo.write(p);
       delay(10);
       
       digitalWrite(12,HIGH);
       delay(10);
       digitalWrite(12,LOW);
       duration=pulseIn(13,HIGH)/2;
       distance = duration/29;
       if(distance>5)
       {
        for(r=p;r=0;r--)
        {
          myservo.write(r);
          delay(10);
        }
       }
    }
}
}
