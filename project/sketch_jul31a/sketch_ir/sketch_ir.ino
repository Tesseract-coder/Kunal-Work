#define irLedPin 4          // IR Led on this pin
#define irSensorPin 5       // IR sensor on this pin
int irRead(int readPin, int triggerPin); //function prototype
void setup()
{
  pinMode(irSensorPin, INPUT);
  pinMode(irLedPin, OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600); 
}
void loop()
{ 
int irsens = int irRead(int readPin,int triggerPin); //taking input from sensor
}
if(irsens = 0)
{ digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  delay(1000); //wait for the string to be sent
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
}
int irRead(int readPin, int triggerPin)
{
  int halfPeriod = 13; //one period at 38.5khZ is aproximately 26 microseconds
  int cycles = 38; //26 microseconds * 38 is more or less 1 millisecond
  int i;
  for (i=0; i <=cycles; i++)
  {
    digitalWrite(triggerPin, HIGH); 
    delayMicroseconds(halfPeriod);
    digitalWrite(triggerPin, LOW); 
    delayMicroseconds(halfPeriod - 1);     // - 1 to make up for digitaWrite overhead    
  }
  return digitalRead(readPin);
}
