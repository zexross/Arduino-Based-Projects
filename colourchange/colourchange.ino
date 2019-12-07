
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(A0,A1); // RX, TX

#define LED_PIN 13
int state = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(3, INPUT_PULLUP); 
  Bluetooth.begin(38400); // Default communication rate of the Bluetooth module
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {

 if (digitalRead == 0) {
  Bluetooth.println("r");
 }
 else if (digitalRead == 1) {
  Bluetooth.println("g");
 } 
}
