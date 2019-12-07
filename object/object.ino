
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

  ball ball1;
  obstacle obstacle1;

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
  ball1.drawball();
  display.drawLine(2,display.height()-6,display.width(),display.height()-6,WHITE);
  obstacle1.drawObstacle();
  display.display();
  delay(2000);
  if(Switch == LOW){
    display.drawCircle(7,display.height()-13-w,i,WHITE);
  }
}


