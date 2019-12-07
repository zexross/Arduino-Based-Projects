
#include <Arduino.h>

// FMS PIC protocol for connecting a PPM stream to a PC.
// http://modelsimulator.com/
//
// Implements the 19200 baud FMS PIC protocol
// Converted from code by
// Richard.Prinz@MIN.at 3.2013
//
// This sketch will find the syncpulse and encode it as 0xFF, and encode
// the individual channels in sequence with the proportional value for each
// channel from 0x00 to 0xFE.
// The code will continue to encode channels regardless of their number
// until the next syncpulse.
//
// The PPM sigmal from the transmitter (or receiver, if it can suply a PPM signal)
// is connected to pin 3, external interupt 1. The Arduino board communicates with
// the computer through the serial port, thus being able to connect throug USB
// interface.
//
// The code uses the timer interrupt through the MsTimer2 library. This can be omitted
// if not wanted. It just adds the capability to send a "heartbeat" signal to the
// simulator if no PPM signal is detected for a while.
// http://playground.arduino.cc/Main/MsTimer2
//
// by Reynir Siik
// 2015-MAR-14, Pi day
//

#define CO                3.9215686
// 1000/255 == 3.9215686

#define THROTTLE_PIN A0
#define ROLL_PIN A1
#define PITCH_PIN A2
#define YAW_PIN A3


#define THROTTLE 0
#define ROLL 1
#define PITCH 2
#define YAW 3



volatile unsigned int stickPin[]={
    THROTTLE_PIN,
    ROLL_PIN,
    PITCH_PIN,
    YAW_PIN
};

volatile unsigned int currentStick=0;
unsigned char data;
unsigned int stick[6];

void setup()
{
  Serial.begin(19200);
  pinMode(THROTTLE_PIN,0);
  pinMode(ROLL_PIN,0);
  pinMode(PITCH_PIN,0);
  pinMode(YAW_PIN,0);
}



void loop()
{
Serial.write(255);  

currentStick=0;
while(currentStick<6)
{
  readJoystick();
  data=(int)(stick[currentStick]/CO);
  Serial.write(data);  
  currentStick=currentStick+1;
//Serial.println(data);  
//delay(100);  
}
delay(10);
}


void readJoystick()
{
  if(currentStick==THROTTLE||currentStick==PITCH)
  stick[currentStick]=map(analogRead(stickPin[currentStick]), 0, 1024,998,0);
  else if(currentStick<4)
  stick[currentStick]=map(analogRead(stickPin[currentStick]), 0, 1024,0,998);
  else
  stick[currentStick]=128;
}

