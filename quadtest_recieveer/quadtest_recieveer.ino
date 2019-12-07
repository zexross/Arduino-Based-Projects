// MOSI 11
// MISO 12
// SCK  13

#include <SPI.h>
#include "RF24.h"
#include<Servo.h>
Servo ese1, ese2, ese3, ese4;
bool radioNumber = 1;
int throttle;

RF24 radio(9, 10); // CE, CSN

byte addresses[][6] = {"90001","10902  "};


void setup() {

 ese1.attach(3);
 ese2.attach(5);
 ese3.attach(6);
 //ese4.attach(9);
 ese1.writeMicroseconds(1000);
 ese2.writeMicroseconds(1000);
 ese3.writeMicroseconds(1000);
// ese4.writeMicroseconds(1000);
    Serial.begin(115200);
    Serial.println(F("Reciever"));
  
  radio.begin();
  //radio.setAutoAck(false);
 // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  
  // Start the radio listening for data
  radio.startListening();
}
void loop() {
  int RecievedData;
  unsigned long start_time = micros();
while(radio.available()){
radio.read( &RecievedData, sizeof(int) );
//Serial.println(RecievedData);

throttle = map(RecievedData,0,1023,1000,2000);
ese1.writeMicroseconds(throttle);
ese2.writeMicroseconds(throttle);
ese3.writeMicroseconds(throttle);
//ese4.writeMicroseconds(throttle);
}
}
