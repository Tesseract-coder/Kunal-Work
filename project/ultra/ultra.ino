long dur, dis;
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(8,INPUT);
pinMode(6,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(9,LOW);
delayMicroseconds(2);
digitalWrite(9,HIGH);
delayMicroseconds(10);
digitalWrite(9,LOW);
//delayMicroseconds(2);
dur = pulseIn(9,HIGH);
dis = dur/58;
analogWrite(6,dis);
delay(100);
}
