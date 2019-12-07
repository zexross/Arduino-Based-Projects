const int a=2;
const int b=3;
const int c=4;
const int d=5;
const int e=6;
const int f=7;
const int g=8;
const int h=9;
int x;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
  pinMode(12,OUTPUT); 
  pinMode(13,INPUT);
  Serial.begin(9600);
}
int duration,distance;
void loop() {
 digitalWrite(12,HIGH);
 delay(10);
digitalWrite(12,LOW);
 duration=pulseIn(13,HIGH)/2;delay(1000);
 distance = duration/29;
 segment(distance);
 Serial.println(distance);
 //for beep assistance while parking
  digitalWrite(10,HIGH);
  delay(duration);
  digitalWrite(10,LOW);
  delay(duration);
  delay(2000);
 
}


void segment(int distance)
  {
        switch(distance)
  {case 0:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  break;
  case 1:
  digitalWrite(b,1);
  digitalWrite(c,1);
  break;
  case 2:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(g,1);
  break;
  case 3:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(g,1);
  break;
  case 4:
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
 break;
  case 5:
  digitalWrite(a,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
  case 6:
  digitalWrite(a,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
  case 7:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  break;
  case 8:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
  case 9:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  break;
  }
}
