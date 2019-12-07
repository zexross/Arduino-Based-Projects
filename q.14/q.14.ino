void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  Serial.begin(9600);

}
 int a=0,b;

void loop() {
  // put your main code here, to run repeatedly:
  b=digitalRead(2);
  delay(50);
  
  if(b==0)
  {
   switch(a)
    {
    case 0:
    digitalWrite(3,1);
    a++;
    break;
    case 1:
    digitalWrite(3,0);
    a--;
    break;
  }
  delay(300);

  }
}
