import processing.serial.*;
Serial myPort;
String ss;
int w, h;
int r,test;

int initial_score,final_score;
int lives = 0,remaining;

float xball;
float yball;
float xaimer;
float yaimer;
float ydelta=-1;
float xdelta=1;
float xaimer_delta = 1;
int count;
void setup()
{
  myPort = new Serial(this, "COM3", 115200); 
  myPort.bufferUntil('\n');
  size(1000,700,P2D);
  background(98,24,233);
  frameRate(240);
  xball = width/2;
  yball = 4*height/5;
  xaimer = width/2-50;
  yaimer = 4*height/5+10;
}
void serialEvent (Serial myPort)
{
  ss = myPort.readStringUntil('\n'); 
  test = atoi();
  println(test);
}

void draw()
{
  background(98,24,233);
  fill(120,50,155);
  stroke(135,40,55);
  strokeWeight(2);
  ellipse(xball,yball,20,20);
  fill(150,50,60);
  stroke(145,45,50,10);
  strokeWeight(1);
  rect(xaimer,yaimer,100,10,10);
  remaining = 3 - lives;
  textSize(10); 
  fill(200, 10, 110);
  text("lives remaining:"+ remaining, 10, 10);
  
  xball=xball+xdelta;
  yball=yball+ydelta;
  
  if(test<3200){
    xaimer=xaimer+xaimer_delta;
  }
 if(test>3400){
   xaimer=xaimer-xaimer_delta;
  }
  if(xaimer<0){
    xaimer=0;
  }
  if(xaimer>width){
    xaimer=width;
  }
  if(xball-10<0||xball+10>width)
  {
    xdelta=-xdelta;
  }
  if(yball-10<0)
  {
    ydelta=-ydelta;
  }
  if(yball>=yaimer && xball<xaimer+100 && xball>xaimer){
    ydelta=-ydelta;
    count = millis()/500;
  }
  
  if(yball>4*height/5+30){
   switch (lives){
     case 0:
     xball = width/2;
     yball = 4*height/5;
     xaimer = width/2-50;
     yaimer = 4*height/5+10;
     lives++;
     break;
     case 1:
     xball = width/2;
     yball = 4*height/5;
     xaimer = width/2-50;
     yaimer = 4*height/5+10;
     lives++;
     break;
     case 2:
     xball = width/2;
     yball = 4*height/5;
     xaimer = width/2-50;
     yaimer = 4*height/5+10;
     lives++;
     break;
     case 3:
     gameover();
     break;
   }
  }
}
 void gameover(){
   final_score = count;
   background(98,24,233);
   textSize(35); 
   fill(255, 0, 255);
   text("GAME OVER", width/2-170, height/2);
   text("score:"+final_score, width/2-170, height/2+100);
 }
 int atoi()
{
  int S=0;
  int l = ss.length();
  for(int i =0;i<l-2;i++)
  {
    S=S*10+ss.charAt(i)-'0';
  }
  return S;
}  