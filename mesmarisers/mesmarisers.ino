const int ir_l_l=7;
const int ir_l_r=2;
const int ir_c_l=3;
const int ir_c_r=4;
const int ir_r_1=5;
const int ir_r_r=6;

const int ir_l_lb=8;
const int ir_l_rb=9;
const int ir_c_lb=12;
const int ir_c_rb=13;
const int ir_r_1b=0;
const int ir_r_rb=1;

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
 
 pinMode(ir_l_lb,INPUT);
 pinMode(ir_l_rb,INPUT);
 pinMode(ir_c_lb,INPUT);
 pinMode(ir_c_rb,INPUT);
 pinMode(ir_r_1b,INPUT);
 pinMode(ir_r_rb,INPUT);
 
 pinMode(ML_PIN_1,OUTPUT);
 pinMode(ML_PIN_2,OUTPUT);
 pinMode(MR_PIN_1,OUTPUT);
 pinMode(MR_PIN_2,OUTPUT);
 pinMode(MR_PWM,OUTPUT);
 pinMode(ML_PWM,OUTPUT);
 pinMode(finish_led,OUTPUT);
 //Serial.begin(9600);
}
int kp = 4,kd = 2 ,ki = 3, p, i, d, error, previous_error, pid;
int base_speed=150, SPEED=50, left_extreme, right_extreme; 
int ML_speed, MR_speed;
int sensor_1,sensor_2,sensor_3,sensor_4,sensor_5,sensor_6,no_of_active_sensors;
int index = 0;
char sensor_select = 'f',motor_state = 'f',state;
int front_sensor[6]={7,2,3,4,5,6};
int back_sensor[6]={8,9,12,13,0,1};

void loop() {
  // put your main code here, to run repeatedly:
active_sensors();
sensor_reading();
}

void active_sensors(){
  no_of_active_sensors=0;
  switch(sensor_select){
  case 'f':
  for(int i=0;i<=6;i++){
   if(digitalRead(front_sensor[i])==1){
    no_of_active_sensors++; 
   }
  }
  break;
  case 'b':
  for(int i=0;i<=6;i++){
   if(digitalRead(back_sensor[i])==1){
    no_of_active_sensors++; 
   }
  }
  break;
  }
}

void sensor_reading(){
  switch(sensor_select){
   case 'f':
  sensor_1 = digitalRead(ir_l_l);
  sensor_2 = digitalRead(ir_l_r);
  sensor_3 = digitalRead(ir_c_l);
  sensor_4 = digitalRead(ir_c_r);
  sensor_5 = digitalRead(ir_r_1);
  sensor_6 = digitalRead(ir_r_r);
  break;
   case 'b':
  sensor_1 = digitalRead(ir_l_lb);
  sensor_2 = digitalRead(ir_l_rb);
  sensor_3 = digitalRead(ir_c_lb);
  sensor_4 = digitalRead(ir_c_rb);
  sensor_5 = digitalRead(ir_r_1b);
  sensor_6 = digitalRead(ir_r_rb);
  break;
  } 
 

 if(no_of_active_sensors==0 || no_of_active_sensors==1 || no_of_active_sensors==2){

  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==0 && sensor_6==0){
    digitalWrite(ML_PIN_1, HIGH);
    digitalWrite(ML_PIN_2, HIGH);
    digitalWrite(MR_PIN_1, HIGH);
    digitalWrite(MR_PIN_2, HIGH);
    delay(300);
    instsensor_reading();
    if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==0 && sensor_6==0){
    if(sensor_select=='f'){
    sensor_select = 'b';
    motor_state = 'b';
    }
    else if(sensor_select=='b'){
    sensor_select = 'f';
    motor_state = 'f';
    }
   }
  }
  
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==0 && sensor_6==1){
  error = 6;
  pid_calculation();
  motor_control(motor_state);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==1 && sensor_6==1){
  error = 5;
  pid_calculation();
  motor_control(motor_state);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==1 && sensor_6==0){
  error = 4;
  pid_calculation();
  motor_control(motor_state);
  }
   if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==1 && sensor_5==1 && sensor_6==0){
  error = 3;
  pid_calculation();
  motor_control(motor_state);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==1 && sensor_5==0 && sensor_6==0){
  error = 2;
  pid_calculation();
  motor_control(motor_state);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==1 && sensor_4==1 && sensor_5==0 && sensor_6==0){
  error = 0;
  pid_calculation();
  motor_control(motor_state);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==1 && sensor_4==1 && sensor_5==0 && sensor_6==0){
  error = 0;
  pid_calculation();
  motor_control(motor_state);
  }
  if(sensor_1==0 && sensor_2==1 && sensor_3==1 && sensor_4==0 && sensor_5==0 && sensor_6==0){
  error = -1;
  pid_calculation();
  motor_control(motor_state);
  }
  if(sensor_1==0 && sensor_2==1 && sensor_3==0 && sensor_4==0 && sensor_5==0 && sensor_6==0){
  error = -2;
  pid_calculation();
  motor_control(motor_state);
  }
  
  if(sensor_1==1 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==0 && sensor_6==0){
  error = -4;
  pid_calculation();
  motor_control(motor_state);
  }
 }
 
  else if(no_of_active_sensors==4){
  if(sensor_1==0 && sensor_2==0 && sensor_3==1 && sensor_4==1 && sensor_5==1 && sensor_6==1){
  instant_stop();
  delay(300);
  instsensor_reading();
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==0 && sensor_6==0){
  turn_left();
  delay(300);
  switch(sensor_select){
  case 'f':
  while(sensor_4==0){
    turn_left();
    instsensor_reading();
  }
  break;
  case 'b':
  while(sensor_3==0){
    turn_left();
    instsensor_reading();
  }
  }
  }
   else if(sensor_2==1 || sensor_3==1 || sensor_4==1 || sensor_5==1){
   motor_control(motor_state);
   }
  }
  if(sensor_1==1 && sensor_2==1 && sensor_3==1 && sensor_4==1 && sensor_5==0 && sensor_6==0){
  instant_stop();
  delay(300);
  instsensor_reading();
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==0 && sensor_6==0){
  turn_right();
  delay(300);
  switch(sensor_select){
   case 'f':
  while(sensor_3==0){
    turn_right();
    instsensor_reading();
  }
  break;
  case 'b':
  while(sensor_4==0){
    turn_right();
    instsensor_reading();
  }
  break;
  }
  }
  if(sensor_2==1 || sensor_3==1 || sensor_4==1 || sensor_5==1){
  turn_right();
  delay(300);
  switch(sensor_select){
   case 'f':
  while(sensor_3==0){
    turn_right();
    instsensor_reading();
  }
  break;
  case 'b':
  while(sensor_4==0){
    turn_right();
    instsensor_reading();
  }
  break;
  }
  }
  }
 }
else if(no_of_active_sensors==6){
  if(sensor_1==1 && sensor_2==1 && sensor_3==1 && sensor_4==1 && sensor_5==1 && sensor_6==1){
  delay(300);
  instsensor_reading();
  if(sensor_1==1 && sensor_2==1 && sensor_3==1 && sensor_4==1 && sensor_5==1 && sensor_6==1){
  digitalWrite(ML_PIN_1, HIGH);
  digitalWrite(ML_PIN_2, HIGH);
  digitalWrite(MR_PIN_1, HIGH);
  digitalWrite(MR_PIN_2, HIGH);
  delay(10000);
  }
  if(sensor_1==0 && sensor_2==0 && sensor_3==0 && sensor_4==0 && sensor_5==0 && sensor_6==0){
  turn_right();
  delay(300);
  switch(sensor_select){
   case 'f':
  while(sensor_3==0){
    turn_right();
    instsensor_reading();
  }
  break;
  case 'b':
  while(sensor_4==0){
    turn_right();
    instsensor_reading();
  }
  break;
  }
  }
  if(sensor_2==1 || sensor_3==1 || sensor_4==1 || sensor_5==1){
  turn_right();
  delay(300);
  switch(sensor_select){
   case 'f':
  while(sensor_3==0){
    turn_right();
    instsensor_reading();
  }
  break;
  case 'b':
  while(sensor_4==0){
    turn_right();
    instsensor_reading();
  }
  break;
  }
  }
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

  state = 'F';
  store_insruction(state);

  previous_error = error;
}

void turn_left(){
  digitalWrite(ML_PIN_1, HIGH);
  digitalWrite(ML_PIN_2, LOW);
  digitalWrite(MR_PIN_1, LOW);
  digitalWrite(MR_PIN_2, HIGH);
  state = 'R';
  store_insruction(state);
}

void turn_right(){
  digitalWrite(ML_PIN_1, LOW);
  digitalWrite(ML_PIN_2, HIGH);
  digitalWrite(MR_PIN_1, HIGH);
  digitalWrite(MR_PIN_2, LOW);
  state = 'L';
  store_insruction(state);
}

void reverse_pid(){
  int deltaspeed = map(SPEED*pid,-450,400,-140,110);
  ML_speed = base_speed + deltaspeed;
  MR_speed = base_speed - deltaspeed;

  ML_speed = constrain(ML_speed, 0, 255);
  MR_speed = constrain(MR_speed, 0, 255);

  digitalWrite(ML_PIN_1, LOW);
  digitalWrite(ML_PIN_2, HIGH);
  analogWrite(ML_PWM, ML_speed);
  digitalWrite(MR_PIN_1, LOW);
  digitalWrite(MR_PIN_2, HIGH);
  analogWrite(MR_PWM, MR_speed);

  state = 'U';
  store_insruction(state);

  previous_error = error;
}

void store_insruction(char state){
  char learned_path[5000];
  switch(state){
    case 'R':
    learned_path[index] = 'R';
    index++;
    break;
    
    case 'L':
    learned_path[index] = 'L';
    index++;
    break;

    case 'U':
    if(learned_path[index-1]=='U'){
    ;
    }
    else{
    learned_path[index] = 'U';
    index++;
    }    
    break;

    case 'F':
    if(learned_path[index-1]=='F'){
    ;
    }
    else{
    learned_path[index] = 'F';
    index++;
    }
    break;
  }
  //delay(1000);
  if(learned_path[i-1] == 'U'){
    if(learned_path[i-2]=='S' && learned_path[i-1]=='U' && learned_path[i]=='L'){
      learned_path[i-2] = 'R';
      i = i-2;
    }
//    else if(learned_path[i-2]=='' && learned_path[i-1]=='' && learned_path[i]==''){
//      learned_path[i-2] = '';
//      i = i-2;
//    }
//    else if(learned_path[i-2]=='' && learned_path[i-1]=='' && learned_path[i]==''){
//      learned_path[i-2] = '';
//      i = i-2;
//    }
  }
}

void instsensor_reading(){
  switch(sensor_select){
   case 'f':
  sensor_1 = digitalRead(ir_l_l);
  sensor_2 = digitalRead(ir_l_r);
  sensor_3 = digitalRead(ir_c_l);
  sensor_4 = digitalRead(ir_c_r);
  sensor_5 = digitalRead(ir_r_1);
  sensor_6 = digitalRead(ir_r_r);
  break;
   case 'b':
  sensor_1 = digitalRead(ir_l_lb);
  sensor_2 = digitalRead(ir_l_rb);
  sensor_3 = digitalRead(ir_c_lb);
  sensor_4 = digitalRead(ir_c_rb);
  sensor_5 = digitalRead(ir_r_1b);
  sensor_6 = digitalRead(ir_r_rb);
  break;
  }
}

void motor_control(char motor_state){
  switch(motor_state){
    case 'f':
    forward_pid();
  break;
  
  case 'b':
  reverse_pid();
  break;
  }
}
void instant_stop(){
  digitalWrite(ML_PIN_1, HIGH);
  digitalWrite(ML_PIN_2, HIGH);
  digitalWrite(MR_PIN_1, HIGH);
  digitalWrite(MR_PIN_2, HIGH);
  delay(250);
}

