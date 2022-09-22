#include <Servo.h>
Servo myservo;

int line1 =11;
int line2 =10;

int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 = 5;

void setup() {
 pinMode(line1,INPUT);
 pinMode(line2,INPUT);
 pinMode(m1,OUTPUT);
 pinMode(m2,OUTPUT);
 pinMode(v1,OUTPUT);
 pinMode(v2,OUTPUT);
 analogWrite(v1, 0);
 analogWrite(v2, 0);
 myservo.attach(3);
 myservo.write(60); 
Serial.begin(9600);
for (int i =0; i<30; i++)
{
  for (int i =0; i<10; i++)
  {
  Serial.println("left_line");
  Serial.println(digitalRead(line2));
    if(digitalRead(line2)==0)
    {
    myservo.write(20);
    }
    else{
     myservo.write(60);
        }
  digitalWrite(m1, LOW);
  analogWrite(v1, 100);
  delay(50);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  delay(500);
  }
digitalWrite(m2, HIGH);
analogWrite(v2, 100);
delay(30);
analogWrite(v2, 0);
delay(500);

if(digitalRead(line2)==0)
  {
    myservo.write(20);
    }
else{
   myservo.write(60);
    }
for (int i =0; i<10; i++)
{
  Serial.println("left_line");
  Serial.println(digitalRead(line2));
  if(digitalRead(line2)==0)
  {
   myservo.write(20);
    }
    else{
      myservo.write(60);
      }
   digitalWrite(m1, HIGH);
analogWrite(v1, 100);
delay(50);
analogWrite(v1, 0);
analogWrite(v2, 0);
delay(500);

}
}    
}



void loop() {
   
}
