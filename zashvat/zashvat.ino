#include <Servo.h>
Servo servo_8;
int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 = 5; 

void setup() {
  servo_8.attach(8);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
}

void loop() {
servo_8.write(10);
delay(1000);

analogWrite(v1,100);
analogWrite(v2,100);
digitalWrite(m1,1);
digitalWrite(m2,1);
delay(1000);

analogWrite(v1,0);
analogWrite(v2,0);
servo_8.write(100);
delay(1);
  }


  
