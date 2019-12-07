/*4x4 Matrix Keypad connected to Arduino
This code prints the key pressed on the keypad to the serial port*/

#include "Keypad.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {A0,A1,A2,A3}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
lcd.begin(16, 2);
Serial.begin(9600);
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
char sum,diff,multiply,divide;
void loop()
{
//lcd.setCursor(0, 0);
char keypressed_i1 = myKeypad.getKey();
while(keypressed_i1 == NO_KEY){
 keypressed_i1 = myKeypad.getKey();
}
Serial.print(keypressed_i1);
char keypressed_op=myKeypad.getKey();
while(keypressed_op==NO_KEY){
 keypressed_op = myKeypad.getKey();
}
switch(keypressed_op){
  case 'A':
  lcd.write("+");
  Serial.print("+");
  break;
  case 'B':
  lcd.write("-");
  break;
  case 'C':
  lcd.write("*");
  break;
  case 'D':
  lcd.write("/");
  break;
 }
 char keypressed_i2 = myKeypad.getKey();
 while(keypressed_i2==NO_KEY){
 keypressed_i2 = myKeypad.getKey();
 }
lcd.print(keypressed_i2);
Serial.print(keypressed_i2);
Serial.print(" ");
lcd.setCursor(0, 1);
switch(keypressed_op){                                                                                                                                                                                            
  case 'A':
  sum=char(int(keypressed_i1)+int(keypressed_i2));
  lcd.print(sum);
  Serial.print(sum);
  break;
  case 'B':
  diff=char(int(keypressed_i1)-int(keypressed_i2));
  lcd.print(diff);
  break;
  case 'C':
  multiply=char(int(keypressed_i1)*int(keypressed_i2));
  lcd.print(multiply);
  break;
  case 'D':
  divide=char(int(keypressed_i1)/int(keypressed_i2));
  lcd.print(divide);
  break;
 }
}                                                                                                                                                                                                 
