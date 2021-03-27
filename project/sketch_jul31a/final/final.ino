void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT); //intializing all pinmodes for motor
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(4,OUTPUT); //initializing pinmode for ir output

}

void loop() {
  // put your main code here, to run repeatedly:
  int irop=digitalRead(4);
  if(irop==1)
  {
    digitalWrite(2,HIGH); //rotating all motors in clockwise direction
    digitalWrite(3,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(5000);
    digitalWrite(3,HIGH); //rotating all motors in anti-clockwise direction
    digitalWrite(2,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    delay(5000);
  }

}
