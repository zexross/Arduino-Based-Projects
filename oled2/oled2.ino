
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop() 
{
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  for(int i = 0; i<=25; i=i+5){
  display.clearDisplay();
  display.setCursor(0,i);
  display.println("kinfromdev");
  display.display();
  delay(1500);
  }
  for(int i = 25; i>=0; i=i-5){
  display.clearDisplay();
  display.setCursor(0,i);
  display.println("kinfromdev");
  display.display();
  delay(1500);
  }
  
}
