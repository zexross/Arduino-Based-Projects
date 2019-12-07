void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
Serial.begin(9600);
}
int a;
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(A0,1);
digitalWrite(A1,0);
for(a=0;a<=100;a++)
 {
  analogWrite(3,a);
  Serial.println(a);
  delay(100);
 }
}
