const int irsensor=2;
const int irsensor1=4;
int sensordata,sensordata1;
void setup() {
   pinMode(irsensor,INPUT);
   pinMode(irsensor1,INPUT);
   Serial.begin(9600);

}

void loop() {
    sensordata=digitalRead(irsensor);
    if(sensordata==1)
    {Serial.print("white    ");
    delay(1000);}
    else 
    {Serial.print("black    ");
    delay(1000);}
    sensordata1=digitalRead(irsensor1);
    if(sensordata1==1)
    {Serial.print("white    ");
    delay(1000);}
    else 
    {Serial.print("black    ");
    delay(1000);}
    Serial.println(" ");
}
