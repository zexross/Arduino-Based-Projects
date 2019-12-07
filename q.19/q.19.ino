#include<Servo.h>
Servo myservo;
const int p=2,x=A0,y=A1;
void setup() {
 pinMode(p,INPUT_PULLUP);
 pinMode(x,INPUT);
 pinMode(y,INPUT);
 myservo.attach(9);
 myservo.attach(10);
 myservo.attach(11);
 Serial.begin(9600);

}
int m,n,o;
void loop(){
  // put your main code here, to run repeatedly:
m=x_motion(x);
n=y_motion(y);
o=point(p);
if(m>=700&&m<=2100)
{
  myservo.write(180);
  delay(2000);
}
if(m>=0&&m<=300)
{
  myservo.write(0);
  delay(2000);
}
if(n>=700&&n<=2000)
{
  myservo.write(180);
  delay(2000);
}
if(n>=0&&n<=300)
{
  myservo.write(0);
  delay(2000);
}


//code for switch action of joystick when pressed
 if(o==0)
 {
  myservo.write(180);
  delay(500);
  myservo.write(0);
  
 }

}
////////////////////////////
int x_motion(int x) //detects x-motion of joystick
{
  return analogRead(x);
}
/////////////////////////////
int y_motion(int y) //detects y-motion of joystick
{
  return analogRead(y);
}
////////////////////////////
int point(int p) //detecting wether the switch is pressed or not
{
  return digitalRead(p);
}

