#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10,11); // RX, TX

const int p=2,x=A0;
void setup() {
 pinMode(2,OUTPUT);
 pinMode(A0,INPUT);
}
int raw, output, min_val, max_val;
void loop(){
  // put your main code here, to run repeatedly:
raw=TDS_RAW_VALUE(x);
output = map(raw,min_val,max_val);

}
////////////////////////////
int TDS_RAW_VALUE(int x)
{
  return analogRead(x);
}

