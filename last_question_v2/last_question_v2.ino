const int x=A4,y=A5;
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
}
int m,n,o,f,g,h,i;
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
///////////////////////
void reverse(int motor_no, int motorspeed)
{ switch(motor_no)
{
  case 1:

  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  analogWrite(3,motorspeed);
  break;
  case 2:
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  analogWrite(5,motorspeed);
  break;
 }
}
/////////////////////////////
void forward(int motor_no , int motorspeed)
{
  switch(motor_no)
  {
   case 1:
   digitalWrite(A0,HIGH);
   digitalWrite(A1,LOW);
   analogWrite(3,motorspeed);
   break;
   case 2:
   digitalWrite(A2,HIGH);
   digitalWrite(A3,LOW);
   analogWrite(5,motorspeed);
   break;
  }
}
//////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
m=x_motion(x);
n=y_motion(y);

if(m>=700&&m<=2100)
{
  forward(1,200);
  delay(2000);
}
if(m>=0&&m<=300)
{
  reverse(1,200);
  delay(2000);
}
if(n>=700&&n<=2000)
{
  forward(2,200);
  delay(2000);
}
if(n>=0&&n<=300)
{
  reverse(2,200);
  delay(2000);
}
}


