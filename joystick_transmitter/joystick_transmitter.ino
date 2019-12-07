// MOSI 11
// MISO 12
// SCK  13

#include <SPI.h>
#include "RF24.h"

bool radioNumber = 1;

RF24 radio(9, 10); // CE, CSN

byte addresses[][6] = {"59Node","60Node"};

const int x=A0,y=A1;

void setup() {
  Serial.begin(115200);
  Serial.println(F("Transmitter"));
  
  radio.begin();
  //radio.setAutoAck(false);
 // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  
  // Start the radio listening for data
  radio.startListening();
}
   
  unsigned long up = 1;
  unsigned long down = 2;
  unsigned long left = 3;
  unsigned long right = 4;
  int m,n;
void loop() {
  unsigned long start_time = micros();
  radio.stopListening();
m=x_motion(x);
n=y_motion(y);
if(m>0&&m<500)
{
Serial.print(F("sending : "));
Serial.println(0);
if (!radio.write( &up, sizeof(unsigned long) )){
Serial.println(F("failed"));
}
}

if(m>600&&m<1023)
{
Serial.print(F("sending : "));
Serial.println(1);
if (!radio.write( &down, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
}

if(n>0&&n<500)
{
Serial.print(F("sending : "));
Serial.println(2);
if (!radio.write( &left, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
}

if(n>600&&n<1023)
{
Serial.print(F("sending : "));
Serial.println(3);
if (!radio.write( &right, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
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

