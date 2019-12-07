#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10,11); // RX, TX
const int a=2;
const int b=3;
const int c=4;
const int d=5;
const int e=6;
const int f=7;
const int g=8;
const int h=9;

void setup()
{

  Serial.begin(9600);
  bluetooth.begin(38400);
  pinMode(13,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
}
char x;                        
void loop()
{
                        
if(bluetooth.available())
{
 x=bluetooth.read();
 Serial.print(x);
}                   


  if(x=='0'||x=='D')
  {
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,0);
  digitalWrite(h,0);
  Serial.print("0");
  }
  
 if(x==('1'))
 {
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(g,0);
  digitalWrite(h,0);
  Serial.print("1");

 }
 if(x=='2')
 {
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,1);
  digitalWrite(h,0);
  Serial.print("2");

 }
 if(x=='3')
 {
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);
  digitalWrite(h,0);
  Serial.print("3");

  }
 if(x=='4')
 {
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  digitalWrite(h,0);
  Serial.print("4");

 }
 if(x=='5')
 {
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  digitalWrite(h,0);
  Serial.print("5");

 }
 if(x=='6')
 {
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  digitalWrite(h,0);
  Serial.print("6");

  }
  if(x=='7')
  {
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  digitalWrite(h,0);
  Serial.print("7");

  }
  if(x=='8'||x=='B')
  {
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  digitalWrite(h,0);
  Serial.print("8");

  }
  if(x=='9')
  {
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  digitalWrite(h,0);
  Serial.print("9");
  }
  if(x=='A')
  {  
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(h,0);
    Serial.print("A");
  }
  if(x=='C')
  {  
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
    digitalWrite(h,0);
    Serial.print("C");
  }
  if(x=='E')
  {  
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(h,0);
    Serial.print("E");
  }
  if(x=='F')
  {  
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(h,0);
    Serial.print("F");
  }
  while(bluetooth.available()==0)
{
  ;
}
  if(x<'0'||x>'F')
  {  
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
    digitalWrite(h,1);
    Serial.print(". ");
  }
}
  
