#include <Servo.h>
Servo servo1;
int pos=0;
void setup() {
  Serial.begin(9600); 
  servo1.attach(9);
  
}

void loop() {

  for(pos=0 ; pos<180 ; pos++)
  {
    servo1.write(pos);
    delay(10);
  }
  for(pos=180 ; pos>=1 ; pos--)
  {
    servo1.write(pos);
    delay(10);
  }
}
