#include <SPI.h>
#include "RF24.h"

bool radioNumber = 0;

RF24 radio(9, 10);

byte addresses[][6] = {"59Node","60Node"};

void setup() {
 Serial.begin(9600);
 Serial.begin(115200);
 Serial.println(F("Reciver"));
  
  radio.begin();
//  radio.setAutoAck(false);

  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1,addresses[1]);

  // Start the radio listening for data
   radio.startListening();
}
void loop() {

    unsigned long recivedData = 0;
  
      while (!radio.available());                                    // While there is data ready
      radio.read( &recivedData, sizeof(unsigned long) );             // Get the payload
      Serial.println(recivedData);  
}

