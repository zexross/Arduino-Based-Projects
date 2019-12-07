
///////////////////////////////////////////////////////////////////////////////////////////////
     const int MR_PWM = 3;
     const int MR_PIN_1 = 4;
     const int MR_PIN_2 = 5;
     const int ML_PWM = 11;
     const int ML_PIN_1 = 10;
     const int ML_PIN_2 = 9;
     const int BUZZER = 12;
     const int ir_sensor_1 = A0;
     const int ir_sensor_2 = A1;
     const int ir_sensor_3 = A2;
     const int ir_sensor_4 = A3;
     const int ir_sensor_5 = A4;
////////////////////////////////////////////////////////////////////////////////////////////
// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {

     pinMode(MR_PWM,OUTPUT);
     pinMode(MR_PIN_1,OUTPUT);
     pinMode(MR_PIN_2,OUTPUT);
     pinMode(ML_PWM,OUTPUT);
     pinMode(ML_PIN_1,OUTPUT);
     pinMode(ML_PIN_2,OUTPUT);
     pinMode(BUZZER,OUTPUT);
     pinMode(ir_sensor_1,INPUT);
     pinMode(ir_sensor_2,INPUT);
     pinMode(ir_sensor_3,INPUT);
     pinMode(ir_sensor_4,INPUT);
     pinMode(ir_sensor_5,INPUT);


    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    // initialize serial communication
    // (115200 chosen because it is required for Teapot Demo output, but it's
    // really up to you depending on your project)
    Serial.begin(115200);
    while (!Serial); // wait for Leonardo enumeration, others continue immediately

    // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // wait for ready
    Serial.println(F("\nSend any character to begin DMP programming and demo: "));
    while (Serial.available() && Serial.read()); // empty buffer
    while (!Serial.available());                 // wait for data
    while (Serial.available() && Serial.read()); // empty buffer again

    // load and configure the DMP
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }

    // configure LED for output
    pinMode(LED_PIN, OUTPUT);
}

int kp = 6,kd = 5,ki = 2, p, i, d, error, previous_error, pid;
int base_speed=150, SPEED=50, left_extreme, right_extreme; 
int ML_speed, MR_speed,state1,state2;


//void pid_calculation(){
//  p = kp*error;
//  i = ki*(error + previous_error);
//  d = kd*(error - previous_error);
//  pid = p + i + d;
//  //Serial.println(SPEED*pid);
//  if(error>0){
//    state1 = HIGH;
//    state2 = LOW;
//  }
// if(error<0){
//  state1 = LOW;
//  state2 = HIGH;
// }
//}
//
//void motor_control(){
//  int deltaspeed = map(SPEED*pid,-450,400,-140,110);
//  //Serial.println(deltaspeed);
//  ML_speed = base_speed + deltaspeed;
//  MR_speed = base_speed + deltaspeed;
//
//  ML_speed = constrain(ML_speed, 0, 255);
//  MR_speed = constrain(MR_speed, 0, 255);
//  //Serial.print("MR_speed;");
//  //Serial.println(MR_speed);
//  //Serial.print("ML_speed;");
//  //Serial.println(ML_speed);
//  //delay(1000);
//
//  digitalWrite(ML_PIN_1, state1);
//  digitalWrite(ML_PIN_2, state2);
//  analogWrite(ML_PWM, ML_speed);
//  digitalWrite(MR_PIN_1, state1);
//  digitalWrite(MR_PIN_2, state2);
//  analogWrite(MR_PWM, MR_speed);
//
//  previous_error = error;
//  //Serial.print("pervious_error:");
//  //Serial.println(previous_error);
//}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
       mpu_reading();
       pid_calculation();
       motor_control();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
 void mpu_reading(){
  // if programming failed, don't try to do anything
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {
        // other program behavior stuff here
        // .
        // .
        // .
        // if you are really paranoid you can frequently test in between other
        // stuff to see if mpuInterrupt is true, and if so, "break;" from the
        // while() loop to immediately process the MPU data
        // .
        // .
        // .
    }

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            Serial.print("ypr\t");
            int y = ypr[0];
            Serial.print(ypr[0] * 180/M_PI);
            Serial.print("\t");
            int p = ypr[1];
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("\t");
            int r = ypr[2];
            Serial.println(ypr[2] * 180/M_PI);
        #endif
    
        #ifdef OUTPUT_TEAPOT
            // display quaternion values in InvenSense Teapot demo format:
            teapotPacket[2] = fifoBuffer[0];
            teapotPacket[3] = fifoBuffer[1];
            teapotPacket[4] = fifoBuffer[4];
            teapotPacket[5] = fifoBuffer[5];
            teapotPacket[6] = fifoBuffer[8];
            teapotPacket[7] = fifoBuffer[9];
            teapotPacket[8] = fifoBuffer[12];
            teapotPacket[9] = fifoBuffer[13];
            Serial.write(teapotPacket, 14);
            teapotPacket[11]++; // packetCount, loops at 0xFF on purpose
        #endif

        // blink LED to indicate activity
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);

        int yaw_current_level = y;
        int pitch_current_level = p;
        int roll_current_level = r;
        int refernce_level = 0;

        yaw_error = yaw_current_level - refernce_level;
        roll_error = roll_current_level - refernce_level;
        pitch_error = pitch_current_level - refernce_level;
 }
 }
////////////////////////////////////////////////////////////////////////////////////////
void pid_calculation(){
  p = kp*error;
  i = ki*(error + previous_error);
  d = kd*(error - previous_error);
  pid = p + i + d;
  //Serial.println(SPEED*pid);
  void ROLL_CORRECTION(){
  if(error>0){
    throttle_R  = throttle + pid*10;
    throttle_L  = throttle;
  }
 if(error<0){
  throttle_R  = throttle;
  throttle_L  = throttle + pid*10;
 }
 }
 void PITCH_CORRECTION(){
  if(error>0){
    throttle_U  = throttle + pid*10;
    throttle_D  = throttle;
  }
 if(error<0){
  throttle_U  = throttle;
  throttle_D  = throttle + pid*10;
 }
 }
}
/////////////////////////////////////////////////////////////////////////////////////
void motor_control(){
  int deltaspeed = map(SPEED*pid,-450,400,-140,110);
  //Serial.println(deltaspeed);
  ML_speed = base_speed + deltaspeed;
  MR_speed = base_speed + deltaspeed;

  ML_speed = constrain(ML_speed, 0, 255);
  MR_speed = constrain(MR_speed, 0, 255);
  //Serial.print("MR_speed;");
  //Serial.println(MR_speed);
  //Serial.print("ML_speed;");
  //Serial.println(ML_speed);
  //delay(1000);

  digitalWrite(ML_PIN_1, state1);
  digitalWrite(ML_PIN_2, state2);
  analogWrite(ML_PWM, ML_speed);
  digitalWrite(MR_PIN_1, state1);
  digitalWrite(MR_PIN_2, state2);
  analogWrite(MR_PWM, MR_speed);

  previous_error = error;
  //Serial.print("pervious_error:");
  //Serial.println(previous_error);
}
