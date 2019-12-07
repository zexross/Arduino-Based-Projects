const int MR_PWM = 3;
const int MR_PIN_1 = 4;
const int MR_PIN_2 = 5;
const int ML_PWM = 11;
const int ML_PIN_1 = 10;
const int ML_PIN_2 = 9;
const int buzzer = 12;
const int ir_sensor_1 = A0;
const int ir_sensor_2 = A1;
const int ir_sensor_3 = A2;
const int ir_sensor_4 = A3;
const int ir_sensor_5 = A4;
void setup() {
  // put your setup code here, to run once:
pinMode(MR_PWM,OUTPUT);
pinMode(MR_PIN_1,OUTPUT);
pinMode(MR_PIN_2,OUTPUT);
pinMode(ML_PWM,OUTPUT);
pinMode(ML_PIN_1,OUTPUT);
pinMode(ML_PIN_2,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(ir_sensor_1,INPUT);
pinMode(ir_sensor_2,INPUT);
pinMode(ir_sensor_3,INPUT);
pinMode(ir_sensor_4,INPUT);
pinMode(ir_sensor_5,INPUT);
//Serial.begin(9600);
}
int kp = 6,kd = 5,ki = 2, p, i, d, error, previous_error, pid;
int base_speed=150, SPEED=50, left_extreme, right_extreme; 
int ML_speed, MR_speed;

void loop() {
  // put your main code here, to run repeatedly:
sensor_reading();
pid_calculation();
motor_control();
}
void sensor_reading(){
  
  int sensor_1 = digitalRead(ir_sensor_1);
  int sensor_2 = digitalRead(ir_sensor_2);
  int sensor_3 = digitalRead(ir_sensor_3);
  int sensor_4 = digitalRead(ir_sensor_4);
  int sensor_5 = digitalRead(ir_sensor_5);
  
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==1){
  error = -4;
  //Serial.print(error);
  }
   if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==1 && sensor_5==1){
  error = -3;
  //Serial.print(error);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==1 && sensor_5==0){
  error = -2;
  //Serial.print(error);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==1 && sensor_4==1 && sensor_5==0){
  error = -1;
  //Serial.print(error);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==1 && sensor_4==0 && sensor_5==0){
  error = 0;
  //Serial.print(error);
  }
  if(sensor_1==0 && sensor_2==1 && sensor_3==1 && sensor_4==0 && sensor_5==0){
  error = 1;
  //Serial.print(error);
  }
  if(sensor_1==0 && sensor_2==1 && sensor_3==0 && sensor_4==0 && sensor_5==0){
  error = 2;
  //Serial.print(error);
  }
  if(sensor_1==1 && sensor_2==1 && sensor_3==0 && sensor_4==0 && sensor_5==0){
  error = 3;
  //Serial.print(error);
  }
  if(sensor_1==1 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==0){
  error = 4;
  //Serial.print(error);
  }
  if(sensor_1==1 && sensor_2==1 && sensor_3==0 && sensor_4==1 && sensor_5==1){
    delay(1000);
  digitalWrite(ML_PIN_1, HIGH);
  digitalWrite(ML_PIN_2, HIGH);
  digitalWrite(MR_PIN_1, HIGH);
  digitalWrite(MR_PIN_2, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(5000);
  }
}
///////////////////////////////////////////////////////////////////////////////
void pid_calculation(){
  p = kp*error;
  i = ki*(error + previous_error);
  d = kd*(error - previous_error);
  pid = p + i + d;
  left_extreme = SPEED*(kp*-4+ki*-8+10);
  right_extreme = SPEED*(kp*4+ki*8+10);
  //Serial.println(SPEED*pid);
}
/////////////////////////////////////////////////////////////////////////////////////
void motor_control(){
  int deltaspeed = map(SPEED*pid,-450,400,-140,110);
  //Serial.println(deltaspeed);
  ML_speed = base_speed + deltaspeed;
  MR_speed = base_speed - deltaspeed;

  ML_speed = constrain(ML_speed, 0, 255);
  MR_speed = constrain(MR_speed, 0, 255);
  //Serial.print("MR_speed;");
  //Serial.println(MR_speed);
  //Serial.print("ML_speed;");
  //Serial.println(ML_speed);
  //delay(1000);

  digitalWrite(ML_PIN_1, HIGH);
  digitalWrite(ML_PIN_2, LOW);
  analogWrite(ML_PWM, ML_speed);
  digitalWrite(MR_PIN_1, HIGH);
  digitalWrite(MR_PIN_2, LOW);
  analogWrite(MR_PWM, MR_speed);

  previous_error = error;
  //Serial.print("pervious_error:");
  //Serial.println(previous_error);
}
