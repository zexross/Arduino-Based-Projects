const int a=2;
const int b=3;
const int c=4;
const int d=5;
const int e=6;
const int f=7;
const int g=8;
const int h=9;
const int i=11;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
  pinMode(h,OUTPUT);
  Serial.begin(9600);
}

void loop() {
   int x,z,w;

 Serial.println("enter a number:");
  while(Serial.available()==0)
  {
    ;
  }
  x = Serial.parseInt();

  Serial.println("provide the intensity between 0 to 5:");
    while(Serial.available()==0)
  {
    ;
  }
  z = Serial.parseInt(); 
  w=250-50*z;
  Serial.println(z);
  Serial.println(w);
  if(x<0||x>9)
  {
    digitalWrite(h,1);
    analogWrite(i,w);
    Serial.println("working dot");
  }
  segment(x,w);
  delay(5000);
}
  void segment(int x,int w)
  {
        switch(x)
  {case 0:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  analogWrite(i,w);
  Serial.println("working 1");
  break;
  case 1:
  digitalWrite(b,1);
  digitalWrite(c,1);
  analogWrite(i,w);
  Serial.println("working 2");
  break;
  case 2:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(g,1);
  analogWrite(i,w);
  Serial.println("working 2");
  break;
  case 3:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(g,1);
  analogWrite(i,w);
  Serial.println("working 3");
  break;
  case 4:
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  analogWrite(i,w);
  Serial.println("working 4");
 break;
  case 5:
  digitalWrite(a,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  analogWrite(i,w);
  Serial.println("working 5");
  break;
  case 6:
  digitalWrite(a,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  analogWrite(i,w);
  Serial.println("working 6");
  break;
  case 7:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  analogWrite(i,w);
  Serial.println("working 7");
  break;
  case 8:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  analogWrite(i,w);
  Serial.println("working 8");
  break;
  case 9:
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  analogWrite(i,w);
  Serial.println("working 9");
  break;
  }
}
