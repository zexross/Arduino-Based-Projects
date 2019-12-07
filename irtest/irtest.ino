const int a=2;
void setup() {
  // put your setup code here, to run once:
 pinMode(a,INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(a)==1)
  Serial.println("white");
  else if(digitalRead(a)==0)
  Serial.println("black");
  

}
