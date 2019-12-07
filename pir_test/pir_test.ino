void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT);
Serial.begin(9600);
}
int x;
void loop() {
  // put your main code here, to run repeatedly:
  x=digitalRead(3);
  Serial.print(x);
}
