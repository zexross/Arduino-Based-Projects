#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10,11); // RX, TX
const int RED_LED=2,GREEN_LED=3,BLUE_LED=4;
void setup()
{

  Serial.begin(9600);
  bluetooth.begin(38400);
  pinMode(13,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
}
char a;                       
void loop()
{
                        
if(bluetooth.available())
{
 a=bluetooth.read();
Serial.print(a);
}
if(a=='r')
{
  digitalWrite(2,1);
  digitalWrite(4,0);
  digitalWrite(3,0);
}
if(a=='g')
{
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(2,0);
}
if(a=='b')
{
  digitalWrite(4,1);
  digitalWrite(2,0);
  digitalWrite(3,0);
}
if(a=='y')
{
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,0);
}
if(a=='m')
{
  digitalWrite(2,1);
  digitalWrite(4,1);
  digitalWrite(3,0);
}
if(a=='c')
{
  digitalWrite(3,1);
  digitalWrite(4,1);
digitalWrite(2,0);
}
if(a=='w')
{
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
}
if(a=='B')
{
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
}


                        
}
