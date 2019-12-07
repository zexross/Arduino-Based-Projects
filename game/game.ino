const int pir_sensor=2;
const int Switch=3;
const int buzzer=4;
const int uv_trigger=12;
const int uv_echo=13;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pir_sensor,INPUT);
pinMode(uv_trigger,OUTPUT);
pinMode(uv_echo,INPUT);
pinMode(Switch,INPUT_PULLUP);
pinMode(buzzer,OUTPUT);
}
int duration,distance,count=0,result,a;
void loop() {
digitalWrite(12,HIGH);
delay(10);
digitalWrite(12,LOW);
 duration=pulseIn(13,HIGH)/2;delay(1000);
 distance = duration/29;
 while(distance<=50)
 {
  if(digitalRead(pir_sensor))
 {
 Serial.write("\r\n hello visitor,please wait for the system to start.");
 delay(2000);
 Serial.write("\r\n lets check your response time. press the switch as soon as start displays on the screen.");
 delay(2000);
 Serial.write("\r\n start");
  while(digitalRead(Switch)==1)
  {
    count++;
  
    delay(10);
  }
 if(count>=100)
 {
  Serial.write("\r\n you are too slow");
 }
 else
 {
  result=count/10;
  Serial.write("\r\n your responce level in scale of 1 to 10 is:");
  Serial.print(result);
 }
 digitalWrite(buzzer,HIGH);
 delay(500);
 digitalWrite(buzzer,LOW);
 delay(5000);
 } 
 }
}
 
 
 
