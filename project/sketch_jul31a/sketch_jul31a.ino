int motor1=9;
int motor2=8;
void setup() {
  // put your setup code here, to run once:
pinMode(motor1,OUTPUT);
pinMode(motor2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(motor1,HIGH);
digitalWrite(motor2,LOW);
delay(6000);
digitalWrite(motor2,HIGH);
digitalWrite(motor1,LOW);
delay(6000);
}
