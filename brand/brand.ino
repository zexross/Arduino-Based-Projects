//#include <SoftwareSerial.h>
//SoftwareSerial Bluetooth(10,11); // RX, TX

const int x=A0,y=A1;
void setup() {
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 Serial.begin(9600); // Default communication rate of the Bluetooth module
}
int m,n,state;
void loop(){
  // put your main code here, to run repeatedly:
m=x_motion(x);
//Serial.println(m);
n=y_motion(y);
//state=map(m,0,1023,0,1000);
//state=map(n,0,1023,4000,6000);
//Serial.println(state);
if(m>0&&m<500)
{
Serial.println(8);
  
}

if(m>600&&m<1023)
{
Serial.println(2);  
}

if(n>0&&n<500)
{
Serial.println(4);  
}

if(n>600&&n<1023)
{
Serial.println(6);  
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

