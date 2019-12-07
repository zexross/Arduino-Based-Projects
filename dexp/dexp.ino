//#include <SoftwareSerial.h>
//SoftwareSerial Bluetooth(10,11); // RX, TX

const int p=2,x=A0,y=A1;
void setup() {
 pinMode(2,INPUT_PULLUP);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 Serial.begin(9600); // Default communication rate of the Bluetooth module
}
int m,n;
void loop(){
  // put your main code here, to run repeatedly:
m=x_motion(x);
n=y_motion(y);
if(m>0&&m<500)
{
Serial.println(0);
 
}

if(m>600&&m<1023)
{
Serial.println(1);  
}

if(n>0&&n<500)
{
Serial.println(2);  
}

if(n>600&&n<1023)
{
Serial.println(3);  
}
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

