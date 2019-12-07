void setup() {
  pinMode(12,OUTPUT); 
  pinMode(13,INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);

}
int duration,distance;
void loop() {
  digitalWrite(12,HIGH);
 delay(10);
digitalWrite(12,LOW);
 duration=pulseIn(13,HIGH)/2;delay(1000);
 distance = duration/29;
 Serial.println(distance);
 while(distance<=560)
 {
  digitalWrite(3,HIGH);
  delay(duration*100);
  digitalWrite(3,LOW);
  delay(duration*100);
 }

 delay(100);

}
