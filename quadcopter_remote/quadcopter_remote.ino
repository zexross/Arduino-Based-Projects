// MOSI 11
// MISO 12
// SCK  13

#include <SPI.h>
#include "RF24.h"

bool radioNumber = 1;

RF24 radio(4, 7); // CE, CSN

byte addresses[][6] = {"90001","10902  "};

const int x_L=A0,y_L=A1,x_R=A3,y_R=A2,joypresss=2,buzzer=3,mswitch_1=5,mswitch_2=6,mswitch_3=8,mswitch_4=9;

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
   
  unsigned long up_R = 1;
  unsigned long down_R = 2;
  unsigned long left_R = 3;
  unsigned long right_R = 4;
  unsigned long up_L = 5;
  unsigned long down_L = 6;
  unsigned long left_L = 7;
  unsigned long right_L = 8;
  unsigned long switch_1 = 9;
  unsigned long switch_2 = 10;
  unsigned long switch_3 = 11;
  unsigned long switch_4 = 12;
  int m,n,o,p;
void loop() {
  unsigned long start_time = micros();
  radio.stopListening();
m=x_motion(x_L);
n=y_motion(y_L);
if(m>0&&m<500)
{
Serial.print(F("sending : "));
Serial.println("1");
if (!radio.write( &up_L, sizeof(unsigned long) )){
Serial.println(F("failed"));
}
}

if(m>600&&m<1023)
{
Serial.print(F("sending : "));
Serial.println("2");
if (!radio.write( &down_L, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
}

if(n>0&&n<500)
{
Serial.print(F("sending : "));
Serial.println("3");
if (!radio.write( &left_L, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
}

if(n>600&&n<1023)
{
Serial.print(F("sending : "));
Serial.println("4");
if (!radio.write( &right_L, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
}
o=x_motion(x_R);
p=y_motion(y_R);
if(o>0&&o<500)
{
Serial.print(F("sending : "));
Serial.println("5");
if (!radio.write( &up_R, sizeof(unsigned long) )){
Serial.println(F("failed"));
}
}

if(o>600&&o<1023)
{
Serial.print(F("sending : "));
Serial.println("6");
if (!radio.write( &down_R, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
}

if(p>0&&p<400)
{
Serial.print(F("sending : "));
Serial.println("7");
if (!radio.write( &left_R, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
}

if(p>600&&p<1023)
{
Serial.print(F("sending : "));
Serial.println("8");
if (!radio.write( &right_R, sizeof(unsigned long) )){
Serial.println(F("failed"));
}  
}
if(momentaryswitch(mswitch_1)==HIGH){
Serial.print(F("sending : "));
Serial.println("9");
if (!radio.write( &switch_1, sizeof(unsigned long) )){
Serial.println(F("failed"));
}
}

if(momentaryswitch(mswitch_2)==HIGH){
Serial.print(F("sending : "));
Serial.println("10");
if (!radio.write( &switch_1, sizeof(unsigned long) )){
Serial.println(F("failed"));
}
}

if(momentaryswitch(mswitch_3)==HIGH){
Serial.print(F("sending : "));
Serial.println("11");
if (!radio.write( &switch_1, sizeof(unsigned long) )){
Serial.println(F("failed"));
}
}

if(momentaryswitch(mswitch_4)==HIGH){
Serial.print(F("sending : "));
Serial.println("12");
if (!radio.write( &switch_1, sizeof(unsigned long) )){
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
/////////////////////////////
int momentaryswitch(int s)
{
  return digitalRead(s);
}
