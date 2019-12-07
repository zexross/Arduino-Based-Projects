const int a=3;
const int b=5;
const int c=6;
const int d=9;
const int e=10;
const int f=11;
const int g=A0;
const int h=A1;
void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int x,w,z;

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
  w=50*z;
  if(x<0||x>9)
  {
    analogWrite(h,w);
  }
  else
  {
   segment(x,w);
  }
  delay(5000);
}
  void segment(int x, int w)
  {
        switch(x)
   {
    case 0:
          analogWrite(a,w);
          analogWrite(b,w);
          analogWrite(c,w);
          analogWrite(d,w);
          analogWrite(e,w);
          analogWrite(f,w);
    break;
    case 1:
         analogWrite(b,w);
         analogWrite(c,w);
    break;
    case 2:
        analogWrite(a,w);
        analogWrite(b,w);
        analogWrite(d,w);
        analogWrite(e,w);
        analogWrite(g,w);
    break;
    case 3:
       analogWrite(a,w);
       analogWrite(b,w);
       analogWrite(c,w);
       analogWrite(d,w);
       analogWrite(g,w);
    break;
    case 4:
       analogWrite(b,w);
       analogWrite(c,w);
       analogWrite(f,w);
       analogWrite(g,w);
    break;
    case 5:
       analogWrite(a,w);
       analogWrite(c,w);
       analogWrite(d,w);
       analogWrite(f,w);
       analogWrite(g,w);
    break;
    case 6:
       analogWrite(a,w);
       analogWrite(c,w);
       analogWrite(d,w);
       analogWrite(e,w);
       analogWrite(f,w);
       analogWrite(g,w);
    break;
    case 7:
       analogWrite(a,w);
       analogWrite(b,w);
       analogWrite(c,w);
    break;
    case 8:
       analogWrite(a,w);
       analogWrite(b,w);
       analogWrite(c,w);
       analogWrite(d,w);
       analogWrite(e,w);
       analogWrite(f,w);
       analogWrite(g,w);
    break;
    case 9:
       analogWrite(a,w);
       analogWrite(b,w);
       analogWrite(c,w);
       analogWrite(d,w);
       analogWrite(f,w);
       analogWrite(g,w);
    break;
   }
 }

