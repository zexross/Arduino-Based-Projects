void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
}
int m,n,o,f,g,h,i;
void loop() {
  // put your main code here, to run repeatedly:
 m=x_motion(x);
 n=y_motion(y);
 o=point(p);
  //costraining the values to a specific interval
f=constrain(m,700,2000);
g=constrain(m,0,400);
h=constrain(n,700,2000);
i=constrain(n,0,400);

//mapping the input
f=map(f,700,2000,0,255);
g=map(g,400,0,0,255);
h=map(h,700,2000,0,255);
i=map(i,400,0,0,255);
  
  forward(1,f);
  reverse(1,g);

  forward(2,h);
  reverse(2,i);

}
void forward(int motor no , int motorspeed)
{
  switch(motor no)
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
   
}
///////////////////////
void reverse(int , int motorspeed)
{ switch(motor no)
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
//////////////////////
void Stop(int , int motorspeed)
{ switch(motor no) 
 {
  case 1:

  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  break;
  case 2:
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);
 } break;
}

