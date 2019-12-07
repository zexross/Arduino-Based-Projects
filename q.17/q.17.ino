const int p=2,x=A0,y=A1,a=3,b=4,c=5,d=6,e=7;
void setup() {
 pinMode(p,INPUT_PULLUP);
 pinMode(x,INPUT);
 pinMode(y,INPUT);
 pinMode(a,OUTPUT);
 pinMode(b,OUTPUT);
 pinMode(c,OUTPUT);
 pinMode(d,OUTPUT);
 pinMode(e,OUTPUT);
 Serial.begin(9600);

}
int m,n,o,f,g,h,i;
void loop(){
  // put your main code here, to run repeatedly:
m=x_motion(x);
n=y_motion(y);
o=point(p);

//costraining the values to a specific interval
f=constrain(m,500,1000);
g=constrain(m,0,500);
h=constrain(n,500,1000);
i=constrain(n,0,500);

//mapping the input
f=map(f,500,1000,0,255);
g=map(g,500,0,0,255);
h=map(h,500,1000,0,255);
i=map(i,500,0,0,255);
analogWrite(3,f);
analogWrite(4,g);
analogWrite(5,h);
analogWrite(6,i);
//code for switch action of joystick when pressed
 if(o==0)
 {
  digitalWrite(e,1);
 }
 if(o==1)
 {
  digitalWrite(e,0);
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

