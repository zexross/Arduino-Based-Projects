// DS1307_Serial_Easy 
// Copyright (C)2016 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// A quick demo of how to use my DS1307-library to 
// quickly send time and date information over a serial link
//
// To use the hardware I2C (TWI) interface of the Arduino you must connect
// the pins as follows:
//
// Arduino Uno/2009:
// ----------------------
// DS1307:  SDA pin   -> Arduino Analog 4 or the dedicated SDA pin
//          SCL pin   -> Arduino Analog 5 or the dedicated SCL pin
//
// Arduino Leonardo:
// ----------------------
// DS1307:  SDA pin   -> Arduino Digital 2 or the dedicated SDA pin
//          SCL pin   -> Arduino Digital 3 or the dedicated SCL pin
//
// Arduino Mega:
// ----------------------
// DS1307:  SDA pin   -> Arduino Digital 20 (SDA) or the dedicated SDA pin
//          SCL pin   -> Arduino Digital 21 (SCL) or the dedicated SCL pin
//
// Arduino Due:
// ----------------------
// DS1307:  SDA pin   -> Arduino Digital 20 (SDA) or the dedicated SDA1 (Digital 70) pin
//          SCL pin   -> Arduino Digital 21 (SCL) or the dedicated SCL1 (Digital 71) pin
//
// The internal pull-up resistors will be activated when using the 
// hardware I2C interfaces.
//
// You can connect the DS1307 to any available pin but if you use any
// other than what is described above the library will fall back to
// a software-based, TWI-like protocol which will require exclusive access 
// to the pins used, and you will also have to use appropriate, external
// pull-up resistors on the data and clock signals.
//

#include <DS1307.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


// Init the DS1307
DS1307 rtc(SDA, SCL);

void setup()
{
  // Setup Serial connection
  lcd.begin(16,2);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}

  // Initialize the rtc object
  rtc.begin();
  // Set the clock to run-mode
  rtc.halt(false);
  
  // The following lines can be uncommented to set the time
  //rtc.setDOW(WEDNESDAY);        // Set Day-of-Week to SUNDAY
  //rtc.setTime(16, 11, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(28, 6, 2017);   // Set the date to October 3th, 2010
}

void loop()
{
  lcd.setCursor(0, 0);
  // Send Day-of-Week
  lcd.print(rtc.getDOWStr());
  lcd.print(" ");
  
  // Send date
  lcd.print(rtc.getDateStr());
  lcd.print(" -- ");
  lcd.setCursor(0, 1);
  // Send time
  lcd.println(rtc.getTimeStr());
  
  // Wait one second before repeating :)
  delay (1000);
}
