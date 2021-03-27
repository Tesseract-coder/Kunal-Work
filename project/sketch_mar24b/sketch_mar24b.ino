#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);  
  myservo.write(115); 
  delay(2000);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int i=Serial.read();
  if(i=='1'){
  myservo.write(50); 
    delay(500);
   // int distance = readPing();
   // delay(100);
    myservo.write(115);
    delay(100);
    i==0;
    }
    if(i=='2')
    {myservo.write(170); 
    delay(500);
   // int distance = readPing();
   // delay(100);
    myservo.write(115); 
   // return distance;
    delay(100);
    i==0;
    }
    
}
