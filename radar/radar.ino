#include <Servo.h>
Servo myservo;  
int trig = 12;    
int echo = 13;  
long dur, cm;

void setup() {
myservo.attach(11);
Serial.begin (9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
}
void loop(){

for (int i=0; i<180; i++ ){
      myservo.write(i);              
digitalWrite(trig, LOW);
delayMicroseconds(5);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);
dur = pulseIn(echo, HIGH);
cm = (dur/2) / 29.1;
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(10);
}
 for (int i=180; i>0; i-- ){
   // myservo1.write(i);
    myservo.write(i);                
    delay(10); 
   digitalWrite(trig, LOW);
delayMicroseconds(5);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);
dur = pulseIn(echo, HIGH);
cm = (dur/2) / 29.1;
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(10);
    } 
}
