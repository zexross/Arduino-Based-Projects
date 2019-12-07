#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10,11); // RX, TX
 
void setup()
{
Serial.begin(9600);
bluetooth.begin(38400);
pinMode(13,OUTPUT);
}
                        
void loop()
{
                        
if(bluetooth.available())
{
 Serial.print((char)bluetooth.read());
}
if(Serial.available())
{
 bluetooth.write(Serial.read());
}
                        
}
