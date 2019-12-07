void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

float signal1;
float signal2;
float signal3;
float i;

void loop() {
  // put your main code here, to run repeatedly:
  if(i<195){
    signal1=0;
    signal2=0;
    signal3=0;
    Serial.print(signal1);
   Serial.print(" ");
    Serial.print(signal2);
    Serial.print(" ");
    Serial.println(signal3);
    delay(10);
  }
  for(i=0;i<100;i++){
    signal1 = 75*sin(PI/145*(i+23.24590));
    Serial.print(signal1);
    Serial.print(" ");
    signal2=75*sin(PI/145*23.24590);
    Serial.print(signal2);
    Serial.print(" ");
    if(i<49){
    signal3=75*sin(PI/145*23.24590);
    Serial.println(signal3);
    delay(10);
    }
    else if(i>=49&&i<=50){
    signal3=-50;
    Serial.println(signal3);
    delay(10);
    }
    else if(i==50){
    signal3=75*sin(PI/145*23.22795272);
    Serial.println(signal3);
    delay(10);
    }
    else if(i<100){
     signal3=75*sin(PI/145*23.22795272);
     Serial.println(signal3);
     delay(10);
     }
    
  }
  for(i=0;i<190;i++){
    signal1=0;
    Serial.print(signal1);
    Serial.print(" ");
    signal2=0;
    Serial.print(signal2);
    Serial.print(" ");
    signal3=0;
    Serial.println(signal3);
    delay(10);
  }
}
