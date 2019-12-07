const int x=A4,y=A5;
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
pinMode(x,INPUT);
pinMode(y,INPUT);

}
int m,n,o,f,g,h,i;
////////////////////////////

void loop() {
  // put your main code here, to run repeatedly:
m=x_motion(x);
n=y_motion(y);
/*  //costraining the values to a specific interval
f=constrain(m,700,1024);
g=constrain(m,0,300);
h=constrain(n,700,1024);
i=constrain(n,0,300);

//mapping the input
f=map(f,700,1024,150,255);
g=map(g,300,0,150,255);
h=map(h,700,1024,150,255);
i=map(i,300,0,150,255);
*/
if(m>=700&&m<=2100)
{
  forward(1,255);
  forward(2,255);
  Serial.print("up");
}
if(m>=0&&m<=300)
{
  reverse(1,255);
  reverse(2,255);
  Serial.print("down");
}
if(n>=700&&n<=2000)
{
  forward(1,255);
  reverse(2,255);
  Serial.print("right");
}
if(n>=0&&n<=300)
{
  reverse(1,255);
  forward(2,255);
  Serial.print("left");
 }
}
////////////////////////////////////////////////////////////
void forward(int motor_no , int motorspeed)
{
  switch(motor_no)
  {
   case 1:
   digitalWrite(A0,HIGH);
   digitalWrite(A1,LOW);
   //analogWrite(3,motorspeed);
   break;
   case 2:
   digitalWrite(A2,HIGH);
   digitalWrite(A3,LOW);
   //analogWrite(5,motorspeed);
   
  }
}

///////////////////////
void reverse(int motor_no, int motorspeed)
{ switch(motor_no)
{
  case 1:

  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  //analogWrite(3,motorspeed);
  break;
  case 2:
  digitalWrite(A2,LOW);
  digitalWrite(A3,HIGH);
  //analogWrite(5,motorspeed);
  break;
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
