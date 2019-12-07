
float frequency = 1.0f;
float amplitude = 100.0f;

 void setup() {
   Serial.begin(9600);
 }
 
 void loop() {
   unsigned long time = millis();
   
   float x = time * 0.001f * 2 * PI * frequency;
   float signal = amplitude* sin(x);
   
   // Adding some random noise to the signal
   signal  = random(-100, 101) * 0.0006f * amplitude;
 
   Serial.println(signal);
 
   delay(10);
 }
