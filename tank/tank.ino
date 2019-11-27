/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */
#include <Servo.h>
#include <IRremote.h>

int RECV_PIN = 8;
int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 = 5;
IRrecv irrecv(RECV_PIN);

decode_results results;
Servo myservo; 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  myservo.attach(12); 
  myservo.write(10); 
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    Serial.println(results.value);
    irrecv.resume(); 

    if (results.value == 16720605){
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, LOW);
       digitalWrite(m2, HIGH);
      }
    else if (results.value == 16761405){
      analogWrite(v1, 0);
      analogWrite(v2, 0);
      } 
 else if (results.value == 16712445){
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, HIGH);
       digitalWrite(m2, LOW);
      }
 else if (results.value == 16753245){
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, HIGH);
       digitalWrite(m2, HIGH);
      }
     else if (results.value == 16769565){
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, LOW  );
       digitalWrite(m2, LOW);
      }  

       else if (results.value == 16769055){
      myservo.write(10); 
      } 
      else if (results.value == 16754775){
      myservo.write(170); 
      }   
        else if (results.value == 16748655){
      myservo.write(90); 
      }   
     
  }
}
