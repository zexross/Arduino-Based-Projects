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
int m,n,o;
void loop(){
  // put your main code here, to run repeatedly:
m=x_motion(x);
n=y_motion(y);
o=point(p);
if(m>=700&&m<=2100)
{
  Serial.println("up");
  delay(2000);
}
if(m>=0&&m<=300)
{
  Serial.println("down");
  delay(2000);
}
if(n>=700&&n<=2000)
{
  Serial.println("right");
  delay(2000);
}
if(n>=0&&n<=300)
{
  Serial.println("left");
  delay(2000);
}


//code for switch action of joystick when pressed
 if(o==0)
 {
  Serial.println("press");
  delay(2000);
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

