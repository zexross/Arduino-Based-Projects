#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#include "Keypad.h"
const byte numRows= 4; 
const byte numCols= 4;
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {A5,A4,A3,A2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("Hey!!");

}

void loop() {
  char keypressed = myKeypad.getKey();
if (keypressed != NO_KEY)
lcd.print(keypressed);
}

