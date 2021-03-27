//#define lr 8  // left motor
//#define lb 9
//#define rr 10   // right motor
//#define rb 11
#define handred 4
#define handblck 5
#define gearred 6
#define gearblck 7
#include <SoftwareSerial.h>
#include <stdlib.h>
SoftwareSerial ser(2, 3); // RX, TX
int count;
void up()
{
  digitalWrite(gearred,HIGH);
  digitalWrite(gearblck,LOW);
}
void down()
{
  digitalWrite(gearred,LOW);
  digitalWrite(gearblck,HIGH);
}
void drop()
{
  digitalWrite(handred,HIGH);
  digitalWrite(handblck,LOW);
}
void pick()
{
  digitalWrite(handred,LOW);
  digitalWrite(handblck,HIGH);
}
void forward()
{
 digitalWrite (8,HIGH);
   digitalWrite (9,LOW);
   digitalWrite (10,LOW);
   digitalWrite (11,HIGH);  
}
void backward()
{
   digitalWrite (8,LOW);
   digitalWrite (9,HIGH);
   digitalWrite (10,HIGH);
   digitalWrite (11,LOW);
}
void left()
{
  digitalWrite (8,HIGH);
   digitalWrite (9,LOW);
   digitalWrite (10,LOW);
   digitalWrite (11,LOW); 
   delay(300);
   
}
void right()
{
  digitalWrite (8,LOW);
   digitalWrite (9,LOW);
   digitalWrite (10,LOW);
   digitalWrite (11,HIGH);
   delay(300);
}
void Stop()
{
   digitalWrite(8, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(11, LOW);
   digitalWrite(handred, LOW);
   digitalWrite(handblck, LOW);
   digitalWrite(gearred, LOW);
   digitalWrite(gearblck, LOW);
   
}  
void setup() {
   Serial.begin(115200); 
  // enable software serial
  ser.begin(115200);
   pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(handred, OUTPUT);
  pinMode(handblck, OUTPUT);
  pinMode(gearred, OUTPUT);
  pinMode(gearblck, OUTPUT);
  
  // reset ESP8266
  ser.println("AT+RST");
  delay(3000);
  ser.println("AT+CWMODE=1");
  delay(2000);
  ser.println("AT+CIFSR");
  delay(2000);
  ser.println("AT+CIPMUX=1");
  delay(2000);
  ser.println("AT+CIPSERVER=1,80");
  delay(2000);
  }


void loop() {
  while(ser.available()>0)
  { 
   if(ser.find("+IPD,"))
    {
      delay(200);
      char connectionId=ser.read();
       String getStr="<html><body>";
       getStr+="<a href=\"http://192.168.43.163?f\">";
       getStr+="<button type=\"button\">FORWARD</button></a><br>";
       getStr+="<a href=\"http://192.168.43.163?l\">";
       getStr+="<button type=\"button\">LEFT</button></a>";
       getStr+="<a href=\"http://192.168.43.163?r\">";
       getStr+="<button type=\"button\">RIGHT</button></a>";
       getStr+="<br><a href=\"http://192.168.43.163?b\">";
       getStr+="<button type=\"button\">BACKWARD</button></a><br>";
       getStr+="<a href=\"http://192.168.43.163?s\">";
       getStr+="<button type=\"button\">STOP</button></a><br>";
       getStr+="<a href=\"http://192.168.43.163?p\">";
       getStr+="<button type=\"button\">PICK</button></a>";
       getStr+="<a href=\"http://192.168.43.163?dro\">";
       getStr+="<button type=\"button\">DROP</button></a><br>";
       getStr+="<a href=\"http://192.168.43.163?u\">";
       getStr+="<button type=\"button\">UP</button></a>";
       getStr+="<a href=\"http://192.168.43.163?down\">";
       getStr+="<button type=\"button\">DOWN</button></a></body></html>";
       String cmd = "AT+CIPSEND=";
       cmd += connectionId;
       cmd += ",";
 cmd += String(getStr.length());
 int len = getStr.length();
  ser.print(cmd);
  ser.print(len);
  Serial.print(cmd);
  Serial.println(len);
  delay(3000);
  
//  count=0;
//  do{
//     
//    delay(3000);
//    count++;
//    }while((count<4)||ser.find("OK"));
  

  if(ser.find(">")){
    ser.println(getStr);
    delay(1000);
    for(int i=0;i<3;i++){
    ser.print("AT+CIPCLOSE=");
    ser.println(connectionId);
    }
    Serial.print("AT+CIPCLOSE=");
    Serial.println(connectionId);
    Serial.print("sucess");
    delay(1000);
  }
    }
        if(ser.find("?f HTTP"));{
     Serial.println("forward");
     forward();
     delay(2000); 
    }
     if(ser.find("?b HTTP"));{
     Serial.println("back");
     backward();
     delay(2000); 
    }
     if(ser.find("?r HTTP"));{
     Serial.println("right");
     right();
     delay(2000); 
    }
     if(ser.find("?l HTTP"));{
     Serial.println("left");
     left();
     delay(2000); 
    }
     if(ser.find("?s HTTP"));{
     Serial.println("stop");
     Stop();
     delay(2000); 
    }
     if(ser.find("?up HTTP"));{
     Serial.println("up");
     up();
     delay(2000); 
    }
     if(ser.find("?p HTTP"));{
     Serial.println("pick");
     pick();
     delay(2000); 
    }
     if(ser.find("?dro HTTP"));{
     Serial.println("drop");
     drop();
     delay(2000); 
    }
     if(ser.find("?down HTTP"));{
     Serial.println("down");
     down();
     delay(2000); 
    }

    }
    }
      
