#define motor_debug 1
#if motor_debug
  #define DUMPS(s)  Serial.print(s)
#else
  #define DUMPS(s)
#endif
/////////////////////////////////////////////////////////////////
const int MR_PWM_PIN=3;
const int MR_CONTROL_PIN_A=A0;
const int MR_CONTROL_PIN_B=A1;
const int ML_PWM_PIN=5;
const int ML_CONTROL_PIN_A=A2;
const int ML_CONTROL_PIN_B=A3;
 /////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(5,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
Serial.begin(9600);
}
/////////////////////////////////////////////////////////////////
int motor_no=1;
int motorspeed=200;
/////////////////////////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  DUMPS("/r/nwhich motor do you want to run? left(1) or right(2):");
  while(Serial.available()==0)
  {
    ;
  }
 motor_no = Serial.parseInt();
 DUMPS(motor_no);
 if(motor_no<1||motor_no>2)
 {
  DUMPS("/r/nyou entered invalid motor no:");
  DUMPS(motor_no);
 }
 DUMPS("/r/nprovide the speed of motor ranging from 0 to 255:");
 while(Serial.available()==0)
  {
    ;
  }
 motorspeed = Serial.parseInt();
 DUMPS(motorspeed);
  if(motorspeed<0 || motorspeed>255)
 {
  DUMPS("you entered invalid motor speed:");
  DUMPS(motorspeed);
 }
 /*if(Serial.available()==0)
 {
  motor_no = 1;
  motorspeed = 200;
 }*/ 
 
forward(motor_no, motorspeed);   delay(5000);
stopmotor(motor_no);             delay(2000);
reverse(motor_no, motorspeed);   delay(5000);
stopmotor(motor_no);             delay(2000);

}
/////////////////////////////////////////////////////////////////
void forward(int motor_no , int motorspeed)
{
  switch(motor_no)
  {
   case 1:
   digitalWrite(A0,HIGH);
   digitalWrite(A1,LOW);
   analogWrite(3,motorspeed);
   break;
   case 2:
   digitalWrite(A2,HIGH);
   digitalWrite(A3,LOW);
   analogWrite(5,motorspeed);
   
}
/////////////////////////////////////////////////////////////////
void reverse(int motor_no , int motorspeed)
{ 
  switch(motor_no)
  {
   case 1:
   digitalWrite(A0,LOW);
   digitalWrite(A1,HIGH);
   analogWrite(3,motorspeed);
   break;
   case 2:
   digitalWrite(A2,LOW);
   digitalWrite(A3,HIGH);
   analogWrite(5,motorspeed);
   break;
  }
}
/////////////////////////////////////////////////////////////////
void stopmotor(int motor_no)
{ 
  switch(motor_no) 
 {
  case 1:
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  break;
  case 2:
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);
  break;
 }
}

