// esp8266_test.ino
//
// Plot LM35 data on thingspeak.com using an Arduino and an ESP8266 WiFi 
// module.
//
// Author: Mahesh Venkitachalam
// Website: electronut.in

#include <SoftwareSerial.h>
#include <stdlib.h>
#include<dht.h>
dht DHT;

// if you require to change the pin number, Edit the pin with your arduino pin.

#define DHT11_PIN 3
// LED 
int ledPin = 13;


// replace with your channel's thingspeak API key
String apiKey = "4XYLU5ASOEXZRJKN";

// connect 10 to TX of Serial USB
// connect 11 to RX of serial USB
SoftwareSerial ser(10, 11); // RX, TX

// this runs once
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);    

  // enable debug serial
  Serial.begin(9600); 
  // enable software serial
  ser.begin(115200);
  
  // reset ESP8266
  ser.println("AT+RST");
  delay(1000);
  ser.println("AT+GMR");
  delay(1000);
  ser.println("AT+CWMODE=1");
  delay(1000);
  ser.println("AT+CWJAP=\"eYantra\",\"password\"");
  delay(1000);
  
  
}


// the loop 
void loop() {
  
  // blink LED on board
  digitalWrite(ledPin, HIGH);   
  delay(200);               
  digitalWrite(ledPin, LOW);

  // read the value from LM35.
  // read 10 values for averaging.
  int val = 0;
  int chk = DHT.read11(DHT11_PIN);

Serial.println(" Humidity " );

Serial.println(DHT.humidity);

Serial.println(" Temparature ");

Serial.println(DHT.temperature);

delay(2000);

  // convert to temp:
  // temp value is in 0-1023 range
  // LM35 outputs 10mV/degree C. ie, 1 Volt => 100 degrees C
  // So Temp = (avg_val/1023)*5 Volts * 100 degrees/Volt
  float temp = DHT.temperature*1.0f;
  float temp1 = DHT.humidity*1.0f;
  // convert to string
  char buf[16];
  String strTemp = dtostrf(temp, 4, 1, buf);
  String strTemp1 = dtostrf(temp1, 4, 1, buf);
  
  Serial.println(strTemp);
  Serial.println(strTemp1);
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
   
  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(strTemp);
  getStr +="&field2=";
  getStr += String(strTemp1);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
    
  // thingspeak needs 15 sec delay between updates
  delay(16000);  
}
