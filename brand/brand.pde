import processing.serial.*;
Serial myPort;
float input;
void setup(){
  size(700, 500);
  myPort = new Serial(this, "COM3", 9600); // Starts the serial communication
 myPort.bufferUntil('\n'); // Defines up to which character the data from the serial port will be read. The character '\n' or 'New Line'
}
void serialEvent (Serial myPort){ // Checks for available data in the Serial Port
  input = float(myPort.readStringUntil('\n'));
  print(input);
}
int x=0,y=0;
void draw(){
  background(237, 240, 241);
  fill(20, 160, 133);
  stroke(25);
  strokeWeight(1);
  ellipse(width/2,height/2,50,50);
  while(input==8)
  {
    ellipse(width/2,height/2+y,50,50);
    y++;
  }
  while(input==2)
  {
    ellipse(width/2,height/2-y,50,50);
    y++;
  }
    while(input==6)
  {
    ellipse(width/2+x,height/2,50,50);
    x++;
  }
    while(input==4)
  {
    ellipse(width/2-x,height/2,50,50);
    x++;
  }
}