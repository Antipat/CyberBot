
#include <Servo.h>

Servo myservo;  
 
void setup() {
  myservo.attach(12);  
  myservo.write(30);
  delay(1000);
  myservo.write(100);  
}

void loop() {  

   myservo.write(30);
  delay(3000);
  myservo.write(100); 
  delay(3000);
}
