#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
char received_msg[3];
RF24 radio(9,10);
const uint64_t pipe = 0x17E8F0F0E199;
void setup()
{
 Serial.begin(9600);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
}
void loop()
{
  if (radio.available())
  {    
   while (radio.available()
   {
     radio.read(received_msg, sizeof(received_msg));
     Serial.println(received_msg);
     //received_msg[0]='s';
     delay(10);
    }
   }
   
}
