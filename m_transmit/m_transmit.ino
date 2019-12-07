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
char transmitted_msg = 'j';
RF24 radio(9,10); //CE , CSN
const uint64_t pipe = 0x17E8F0F0E199;                         
void setup()
{
 Serial.begin(115200);
 radio.begin();
 radio.openWritingPipe(pipe);
}
int i =0;
void loop()
{
  Serial.println(radio.write(transmitted_msg, sizeof(transmitted_msg)));
  Serial.println(transmitted_msg);
}
