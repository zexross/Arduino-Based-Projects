const int RED_LED=3;const int GREEN_LED=5;const int YELLOW_LED=6;const int WHITE_LED=9;const int BUZZER=13;const int BUTTON=2;
const int x=A1;
const int y=A2;
int Status;
 int MOTION_X;
 int MOTION_Y;
 int a,b,c,d,R,G,Y,W;
void setup() {Serial.begin(9600);
pinMode(x,INPUT);
pinMode(y,INPUT);
pinMode(BUTTON,INPUT_PULLUP);
pinMode(RED_LED,OUTPUT);pinMode(GREEN_LED,OUTPUT);pinMode(YELLOW_LED,OUTPUT);pinMode(WHITE_LED,OUTPUT);pinMode(BUZZER,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
 char a,b,c,d;
 MOTION_X=analogRead(x);
 MOTION_Y=analogRead(y);
 Status=digitalRead(BUZZER);
 R= constrain(MOTION_X,600,1023);
 G=constrain(MOTION_X,0,400);
 Y=constrain(MOTION_Y,600,1023);
 W=constrain(MOTION_Y,0,400);

 a=map(R,600,1023,'A','M');
 b=map(G,400,0,'N','Z');
 c=map(Y,600,1023,'a','m');
 d=map(W,400,0,'n','z');

 

}
