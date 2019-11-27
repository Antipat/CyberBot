#include <Servo.h>

Servo myservo;  

int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 =  5;

int l1 =11;
int l2 =10;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);
  myservo.attach(3);  
  myservo.write(60);

  analogWrite(6, 0);
  analogWrite(5, 0);
  pinMode(l1,INPUT);
  pinMode(l2,INPUT);
  Serial.begin(9600);

for (int i=0; i<30; i++)
{
  

for (int i=0; i<10; i++)
{
 Serial.println("left_line");
 Serial.println(digitalRead(l2));
 if (digitalRead(l2)==0){
  myservo.write(20);
    }
    else{
      myservo.write(60);
      }
  digitalWrite(m1,LOW);

analogWrite(6, 100);
 //analogWrite(5, 100);
 delay(50);
 
analogWrite(6, 0);
analogWrite(5, 0);
delay(500);

 
}


 digitalWrite(m2,HIGH);

analogWrite(5, 100);
 //analogWrite(5, 100);
 delay(30);
 

analogWrite(5, 0);
delay(500);
if (digitalRead(l2)==0){
  myservo.write(20);
    }

    else{
      myservo.write(60);
      }
      

for (int i=0; i<10; i++)
{
  Serial.println("left_line");
  Serial.println(digitalRead(l2));
if (digitalRead(l1)==0){
  myservo.write(20);
    }

    else{
      myservo.write(60);
      }
digitalWrite(m1,HIGH);
analogWrite(6, 100);
 //analogWrite(5, 100);
 delay(50);
 
  analogWrite(6, 0);
  analogWrite(5, 0);
delay(500);
    }
}
}

void loop() {
  

}
