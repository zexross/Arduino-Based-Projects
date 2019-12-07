const int ir_l_l=7;
const int ir_l_r=2;
const int ir_c_l=3;
const int ir_c_r=4;
const int ir_r_1=5;
const int ir_r_r=6;

//const int ir_l_lb=8;
//const int ir_l_rb=9;
//const int ir_c_lb=12;
//const int ir_c_rb=13;
//const int ir_r_1b=0;
//const int ir_r_rb=1;

const int MR_PWM = 10;
const int ML_PWM = 11;
const int ML_PIN_1=A0;
const int ML_PIN_2=A1;
const int MR_PIN_1=A2;
const int MR_PIN_2=A3;
const int finish_led=A4;
void setup() {
  // put your setup code here, to run once:
 pinMode(ir_l_l,INPUT);
 pinMode(ir_l_r,INPUT);
 pinMode(ir_c_l,INPUT);
 pinMode(ir_c_r,INPUT);
 pinMode(ir_r_1,INPUT);
 pinMode(ir_r_r,INPUT);
 
// pinMode(ir_l_lb,INPUT);
// pinMode(ir_l_rb,INPUT);
// pinMode(ir_c_lb,INPUT);
// pinMode(ir_c_rb,INPUT);
// pinMode(ir_r_1b,INPUT);
// pinMode(ir_r_rb,INPUT);
 
 pinMode(ML_PIN_1,OUTPUT);
 pinMode(ML_PIN_2,OUTPUT);
 pinMode(MR_PIN_1,OUTPUT);
 pinMode(MR_PIN_2,OUTPUT);
 pinMode(MR_PWM,OUTPUT);
 pinMode(ML_PWM,OUTPUT);
 pinMode(finish_led,OUTPUT);
 Serial.begin(9600);
}
int kp = 4,kd = 2,ki = 1, p, i, d, error, previous_error, pid;
int base_speed=150, SPEED=50, left_extreme, right_extreme; 
int ML_speed, MR_speed;
int sensor_1,sensor_2,sensor_3,sensor_4,sensor_5,sensor_6,active;
int index = 0;
int state;
void loop() {
  // put your main code here, to run repeatedly:
active_sensors();
sensor_reading();
}

void active_sensors(){
  active=0;
  for(int i=2;i<=7;i++){
   if(digitalRead(i)==1){
    active++; 
   }
  }
  
}

void sensor_reading(){
  sensor_1 = digitalRead(ir_l_l);
  sensor_2 = digitalRead(ir_l_r);
  sensor_3 = digitalRead(ir_c_l);
  sensor_4 = digitalRead(ir_c_r);
  sensor_5 = digitalRead(ir_r_1);
  sensor_6 = digitalRead(ir_r_r);
  Serial.println("passed");
  if(active<=3){
  Serial.println("2");
  if(sensor_4==0 && sensor_5==0 && sensor_6==1){
  error = 6;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_4==0 && sensor_5==1 && sensor_6==1){
  error = 5;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_4==0 && sensor_5==1 && sensor_6==0){
  error = 4;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_3==0 && sensor_4==1 && sensor_5==1 && sensor_6==0){
  error = 3;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_3==0 && sensor_4==1 && sensor_5==0){
  error = 2;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_2==0 && sensor_3==1 && sensor_4==1 && sensor_5==0){
  error = 0;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_2==0 && sensor_3==1 && sensor_4==0){
  error = -1;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_1==0 && sensor_2==1 && sensor_3==1 && sensor_4==0){
  error = -2;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_1==0 && sensor_2==1 && sensor_3==0){
  error = -3;
  pid_calculation();
  forward_pid();
  }
  else if(sensor_1==1 && sensor_2==0 && sensor_3==0){
  error = -4;
  pid_calculation();
  forward_pid();
  }
 }
  else if(active>=4){
  Serial.println("1");
  char learned_path[500] = {'F','R','R','L','F','F','R','F','F','R','R','L','F','L','R','S'};
  for(int i = 0; i<=15; i++){
  Serial.println(learned_path[i]);
  }
  //state = learned_path[index+1];
  switch(learned_path[i+1]){
    case 'R':
    turn_left();
    delay(755);
    index++;
    break;
    
    case 'L':
    turn_right();
    delay(755);
    index++;
    break;

    case 'F':
    forward_pid();
    delay(400);
    index++;
    break;

     case 'S':
     motor_stop();
     index++;
     break;
  }
 }
}

 void pid_calculation(){
  p = kp*error;
  i = ki*(error + previous_error);
  d = kd*(error - previous_error);
  
  pid = p + i + d;
  left_extreme = SPEED*(kp*-4+ki*-8+10);
  right_extreme = SPEED*(kp*4+ki*8+10);
 }

 void forward_pid(){
  int deltaspeed = map(SPEED*pid,-450,400,-140,110);
  ML_speed = base_speed + deltaspeed;
  MR_speed = base_speed - deltaspeed;

  ML_speed = constrain(ML_speed, 0, 255);
  MR_speed = constrain(MR_speed, 0, 255);

  digitalWrite(ML_PIN_1, HIGH);
  digitalWrite(ML_PIN_2, LOW);
  analogWrite(ML_PWM, ML_speed);
  digitalWrite(MR_PIN_1, HIGH);
  digitalWrite(MR_PIN_2, LOW);
  analogWrite(MR_PWM, MR_speed);

  previous_error = error;
}

void turn_left(){
  digitalWrite(ML_PIN_1, HIGH);
  digitalWrite(ML_PIN_2, LOW);
  digitalWrite(MR_PIN_1, LOW);
  digitalWrite(MR_PIN_2, HIGH);
}

void turn_right(){
  digitalWrite(ML_PIN_1, LOW);
  digitalWrite(ML_PIN_2, HIGH);
  digitalWrite(MR_PIN_1, HIGH);
  digitalWrite(MR_PIN_2, LOW);
}

void motor_stop(){
  delay(100);
  digitalWrite(ML_PIN_1, HIGH);
  digitalWrite(ML_PIN_2, HIGH);
  digitalWrite(MR_PIN_1, HIGH);
  digitalWrite(MR_PIN_2, HIGH);
  delay(15000);
}
