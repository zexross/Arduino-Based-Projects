const int a=10,b=11;
void setup() {
  // put your setup code here, to run once:
pinMode(a,INPUT);
pinMode(b,INPUT);
Serial.begin(9600);
}
int count = 0;
void loop() {
  // put your main code here, to run repeatedly:
int c=0,d=0;
if(digitalRead(a)==1)
{
  
  while(digitalRead(b)==0)
  {  ;  }
  c=digitalRead(a);
  if(digitalRead(b)==1)
  {
  d=digitalRead(b);
  if(c==1&&d==1)
  {
    count++;
   }}
 }
 if(digitalRead(b)==1)
{
  
  while(digitalRead(a)==1)
  {  ;  }
  c=digitalRead(b);
  if(digitalRead(a)==1)
  {
      d=digitalRead(a);
  if(c==1&&d==1)
   {
    count--;
   }
   }
  }
 
 Serial.println(count);
}
