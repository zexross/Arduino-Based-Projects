
const int MOTOR_R_PIN_0 =A0;
const int MOTOR_R_PIN_1 =A1;
const int MOTOR_L_PIN_2=A2;
const int MOTOR_L_PIN_3=A3;
const int IR_SENSOR_1=12;
const int IR_SENSOR_2=13;
int count_1,count_2;
void setup() {
  pinMode( IR_SENSOR_1,INPUT);
  pinMode(IR_SENSOR_2,INPUT);
 pinMode(MOTOR_R_PIN_0,OUTPUT); 
 pinMode(MOTOR_R_PIN_1,OUTPUT);
  pinMode(MOTOR_L_PIN_2,OUTPUT); 
 pinMode(MOTOR_L_PIN_3,OUTPUT);
 
  // put your setup code here, to run once:
}

void loop()
{ 
  count_1= digitalRead(IR_SENSOR_1);
  count_2= digitalRead(IR_SENSOR_2);
 if(count_1==0&&count_2==0)
 {
    digitalWrite(MOTOR_R_PIN_0,HIGH);
    digitalWrite(MOTOR_R_PIN_1,LOW);
    digitalWrite(MOTOR_L_PIN_2,HIGH);
    digitalWrite(MOTOR_L_PIN_3,LOW);
 
  }

if(count_1==1&&count_2==0)
{   digitalWrite(MOTOR_R_PIN_0,HIGH);
    digitalWrite(MOTOR_R_PIN_1,HIGH);
    digitalWrite(MOTOR_L_PIN_2,HIGH);
    digitalWrite(MOTOR_L_PIN_3,HIGH);

    digitalWrite(MOTOR_R_PIN_0,HIGH);
    digitalWrite(MOTOR_R_PIN_1,LOW);
    digitalWrite(MOTOR_L_PIN_2,HIGH);
    digitalWrite(MOTOR_L_PIN_3,HIGH);
 
  }

if(count_1==0&&count_2==1)


{   digitalWrite(MOTOR_R_PIN_0,HIGH);
    digitalWrite(MOTOR_R_PIN_1,HIGH);
    digitalWrite(MOTOR_L_PIN_2,HIGH);
    digitalWrite(MOTOR_L_PIN_3,HIGH);
    
    digitalWrite(MOTOR_R_PIN_0,HIGH);
    digitalWrite(MOTOR_R_PIN_1,HIGH);
    digitalWrite(MOTOR_L_PIN_2,HIGH);
    digitalWrite(MOTOR_L_PIN_3,LOW);}

if(count_1==1&&count_2==1)

{   digitalWrite(MOTOR_R_PIN_0,LOW);
    digitalWrite(MOTOR_R_PIN_1,LOW);
    digitalWrite(MOTOR_L_PIN_2,LOW);
    digitalWrite(MOTOR_L_PIN_3,LOW);}



 
 // put your main code here, to run repeatedly:

}
////////////////////////////////////////

  




