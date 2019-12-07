const int p=2,x=A0,y=A1;
void setup() {
 pinMode(2,INPUT_PULLUP);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 Serial.begin(9600);
}
int m,n,o;
void loop(){
  // put your main code here, to run repeatedly:
m=x_motion(x);
n=y_motion(y);
o=point(p);
Serial.println(m); 
Serial.println(n);
Serial.println(o);
delay(2000);

}
////////////////////////////
int x_motion(int x)
{
  return analogRead(x);
}
/////////////////////////////
int y_motion(int y)
{
  return analogRead(y);
}
////////////////////////////
int point(int p)
{
  return digitalRead(p);
}

