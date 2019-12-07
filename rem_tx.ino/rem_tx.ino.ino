// MOSI 11
// MISO 12
// SCK  13

#include <SPI.h>
#include "RF24.h"
const int SW = 7; 
const int VRY = A0;
const int VRX = A1;
int x;
int y;
int z;

bool radioNumber = 1;

RF24 radio(4, 7); // CE, CSN

byte addresses[][6] = {"TEAM7","7TEAM"};

void setup() {
pinMode(SW, INPUT_PULLUP);
pinMode(VRY, INPUT);
pinMode(VRY, INPUT);

  Serial.begin(115200);
  //Serial.println(F("Transmitter"));
  
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
   
 // unsigned long sendData = 1;
 // unsigned long respondData = 0; 
  
void loop() {
x = map(analogRead(VRY),0,1023,0,500) + 2000;
y = map(analogRead(VRX),0,1023,0,500) + 3000;
  
    unsigned long start_time = micros();
    radio.stopListening();
    radio.write( &x, sizeof(int) );
    radio.write( &y, sizeof(int) );
    //Serial.print(F("sending : "));
    //Serial.println(x);
    Serial.println(y); 

    //sendData = 1 + respondData;
 /*   if (!radio.write( &x, sizeof(int) ) && !radio.write( &y, sizeof(int) ) ){
      Serial.println(x);
      Serial.println(y);
    }
*/    
   // radio.startListening();
   // unsigned long started_waiting_at = micros();
   // boolean timeout = false;
   // while ( ! radio.available() ){
    //  if (micros() - started_waiting_at > 200000 ){
      //    timeout = true;
        //  break;
      }      
    
        
    /*if ( timeout ){                                
        Serial.println(F("Failed, response timed out."));
    }else{
        radio.read( &respondData, sizeof(unsigned long) );
        unsigned long end_time = micros();
       
        Serial.print(F("Sent "));
        Serial.print(x);
        //Serial.print(F(", Got response "));
        //Serial.print(respondData);
        //Serial.print(F(", Round-trip delay "));
       // Serial.print(end_time-start_time);
      //  Serial.println(F(" microseconds"));
    }*/
   // delay(1000);

