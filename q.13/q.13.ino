const int a=2;
const int b=3;
const int c=4;
const int d=5;
const int e=6;
const int f=7;
const int g=8;
const int h=9;
const int i=10;
const int j=11;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
 // pinMode(h,OUTPUT);
  pinMode(i,INPUT_PULLUP);
  pinMode(j,INPUT_PULLUP); 
  Serial.begin(9600);
  
}
int x=0;
void loop() {
  int y,z;
  
  
   segment(x);
  //Serial.println("press 1 for inc. and press 0 for dec.");
  while(Serial.available()!=0)
  {
    ;
  }
  y=digitalRead(i);
  delay(50);

  //y=Serial.parseInt();
  
  if(y==0)
  {  if(x>=9)
      x=9;
     else
     x++;
  }
  z=digitalRead(j);
  delay(50);
  if(z==0)
  {   if(x<=0)
        x=0;
      else
      x--;
  }
 
 Serial.println(x);
 
  }



void segment(int x)
  {
        switch(x)
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
