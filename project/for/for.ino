void forward()
 { digitalWrite (8,HIGH);
   digitalWrite (9,LOW);
   digitalWrite (10,LOW);
   digitalWrite (11,HIGH);
 }
 void back()
 {
   digitalWrite (8,LOW);
   digitalWrite (9,HIGH);
   digitalWrite (10,HIGH);
   digitalWrite (11,LOW);
  }
   void right()
 {
   digitalWrite (8,LOW);
   digitalWrite (9,LOW);
   digitalWrite (10,LOW);
   digitalWrite (11,HIGH);
  }
   void left()
 {
   digitalWrite (8,HIGH);
   digitalWrite (9,LOW);
   digitalWrite (10,LOW);
   digitalWrite (11,LOW);
  }
  int i;
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  }

void loop() {
  Serial.println("enter input");
  i=Serial.read();
  if(i=='1')
  {
    forward();
    delay(1000);
    i==0;
  }
   if(i=='2')
  {
    back();
    delay(1000);
    i==0;
  }
   if(i=='3')
  {
    right();
    delay(1000);
    i==0;
  }
   if(i=='4')
  {
    left();
    delay(1000);
    i==0;
  }
 
  

}
