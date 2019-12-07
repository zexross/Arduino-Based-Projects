/*
  Connections : 
     3.3 - 3.3V
     GND - GND
     MISO - Digital Pin 12
     MOSI - Digital Pin 11
     SCK - Digital Pin 13
*/

#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
char transmitted_msg[3] =  {'j','a','y'};
RF24 radio(9,10); //CE , CSN
const uint64_t pipe =0x17E8F0F0E199;
void setup()
{
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
}
void loop()
{
  Serial.println(radio.write(transmitted_msg, sizeof(transmitted_msg)));
}
