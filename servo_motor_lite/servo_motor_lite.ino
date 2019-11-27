
#include <Servo.h>

Servo myservo;  

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
delay(2000);
}

void loop() {
  for (int i=80; i<160; i++ ){
    //myservo1.write(i);  
    myservo.write(i);              
    delay(10); }                      
  
  for (int i=80; i>160; i-- ){
   // myservo1.write(i);
    myservo.write(i);                
    delay(10); } 
                         
  
}
