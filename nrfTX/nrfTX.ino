// MOSI 11
// MISO 12
// SCK  13

#include <SPI.h>
#include "RF24.h"

bool radioNumber = 1;

RF24 radio(9, 10); // CE, CSN

byte addresses[][6] = {"7Node","8Node"};

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
   
  unsigned long sendData = 1;
  unsigned long respondData = 0; 
  
void loop() {

    unsigned long start_time = micros();
    radio.stopListening();
    Serial.print(F("sending : "));
    
    sendData = 1 + respondData;
    if (!radio.write( &sendData, sizeof(unsigned long) )){
      Serial.println(F("failed"));
    }
    
    radio.startListening();
    unsigned long started_waiting_at = micros();
    boolean timeout = false;
    while ( ! radio.available() ){
      if (micros() - started_waiting_at > 200000 ){
          timeout = true;
          break;
      }      
    }
        
    if ( timeout ){                                
        Serial.println(F("Failed, response timed out."));
    }else{
        radio.read( &respondData, sizeof(unsigned long) );
        unsigned long end_time = micros();
       
        Serial.print(F("Sent "));
        Serial.print(sendData);
        Serial.print(F(", Got response "));
        Serial.print(respondData);
        Serial.print(F(", Round-trip delay "));
        Serial.print(end_time-start_time);
        Serial.println(F(" microseconds"));
    }
    delay(1000);
}
