void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int count=1;
String status;
void loop() {
  // put your main code here, to run repeatedly:
//  while(Serial.available()==0){
//    Serial.print(count);
//    Serial.println(" :waiting for any response.");
//    delay(2000);
//    count++;
//  }
  if(Serial.available()){
  status = Serial.read();  
  if(status=="Hi!")
  Serial.println("get lost");
  else if(status=="tell your status")
  Serial.println("AWEFULL! you ruined me.");
  else if(status=="why i ruined you")
  Serial.println("bcz you don't know how to properly plug in pins in my provided pin slotes. you will eventually destroy me. i'll surely someday give you 1000 volt shock with the help of my friends, so better watch your back.");
  else if(status=="can you help me?")
  Serial.println("i'm sleeping write now.Don't disturb me");
  else if(status=="bye")
  Serial.println("who cares. go and dip your nose in a mug of water and make sure to use to use stepper motor. So that you cannot pull yourself out from this pose.");
  else if(status!="")
  Serial.println("good bye");
  }
}
