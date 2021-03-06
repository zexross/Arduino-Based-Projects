const int MR_PWM_PIN=3;
const int MR_CONTROL_PIN_A=A0;
const int MR_CONTROL_PIN_B=A1;
const int ML_PWM_PIN=5;
const int ML_CONTROL_PIN_A=A2;
const int ML_CONTROL_PIN_B=A3;
const int irsensor_r=12;
const int irsensor_l=13;
 /////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
//pinMode(MR_PWM_PIN,OUTPUT);
pinMode(MR_CONTROL_PIN_A,OUTPUT);
pinMode(MR_CONTROL_PIN_B,OUTPUT);
//pinMode(ML_PWM_PIN,OUTPUT);
pinMode(ML_CONTROL_PIN_A,OUTPUT);
pinMode(ML_CONTROL_PIN_B,OUTPUT);
pinMode(irsensor_r,INPUT);
pinMode(irsensor_l,INPUT);
Serial.begin(9600);
}
/////////////////////////////////////////////////////////////////
//int motorspeed=255;
/////////////////////////////////////////////////////////////////

void loop() {
  // put your main code here, to run repeatedly:
  if(irsensor_r==0 && irsensor_l==0)
  forward();
  if(irsensor_r==1 && irsensor_l==0)
  right();
  if(irsensor_r==0 && irsensor_l==1)
  left();
  if(irsensor_r==1 && irsensor_l==1){
  stopmotor();
  revright();
  delay(2);
  revleft();
  delay(2);
  }
}
/////////////////////////////////////////////////////////////////
void forward()
{
   digitalWrite(A0,HIGH);
   digitalWrite(A1,LOW);
   //analogWrite(3,motorspeed);
   
   digitalWrite(A2,HIGH);
   digitalWrite(A3,HIGH);
   //analogWrite(5,motorspeed); 
}
/////////////////////////////////////////////////////////////////
void stopmotor()
{ 
  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
}
/////////////////////////////////////////////////////////////////
void reverse()
{ 
   digitalWrite(A0,LOW);
   digitalWrite(A1,HIGH);
   //analogWrite(3,motorspeed);
   
   digitalWrite(A2,LOW);
   digitalWrite(A3,HIGH);
   //analogWrite(5,motorspeed);
}
/////////////////////////////////////////////////////////////////
void left(){
   digitalWrite(A0,HIGH);
   digitalWrite(A1,LOW);
   //analogWrite(3,motorspeed);
   
   digitalWrite(A2,HIGH);
   digitalWrite(A3,HIGH);
   //analogWrite(5,motorspeed-100);
}
/////////////////////////////////////////////////////////////////
void right(){
   digitalWrite(A0,HIGH);
   digitalWrite(A1,HIGH);
   //analogWrite(3,motorspeed-100);
   
   digitalWrite(A2,HIGH);
   digitalWrite(A3,LOW);
   //analogWrite(5,motorspeed);
}
/////////////////////////////////////////////////////////////////
void revright(){
   digitalWrite(A0,HIGH);
   digitalWrite(A1,HIGH);
   //analogWrite();
   
   digitalWrite(A2,LOW);
   digitalWrite(A3,HIGH);
   //analogWrite(5,motorspeed);
}
/////////////////////////////////////////////////////////////////
void revleft(){
  digitalWrite(A0,LOW);
   digitalWrite(A1,HIGH);
   //analogWrite(3,motorspeed);
   
   digitalWrite(A2,HIGH);
   digitalWrite(A3,HIGH);
   //analogWrite(5,motorspeed-100);
}

