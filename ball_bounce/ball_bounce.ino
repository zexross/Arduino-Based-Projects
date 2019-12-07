#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10,11); // RX, TX

const int p=2,x=A0,y=A1;
void setup() {
 pinMode(2,INPUT_PULLUP);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 Bluetooth.begin(38400); // Default communication rate of the Bluetooth module
}
int m,n;
void loop(){
  // put your main code here, to run repeatedly:
m=x_motion(x);
n=y_motion(y);
Bluetooth.print (m);
Bluetooth.print (",");
Bluetooth.print (n);
Bluetooth.print("\n");




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

