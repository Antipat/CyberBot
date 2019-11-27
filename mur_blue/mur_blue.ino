
#include <Servo.h> //используем библиотеку для работы с сервоприводом

Servo servo; //объявляем переменную servo типа Servo

int ldr =8;
int ser_enable = A4;

int x;

int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 = 5;




void setup() {
pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);

  pinMode(ser_enable, OUTPUT); 
  digitalWrite(ser_enable, LOW);
  delay(1);
  digitalWrite(ser_enable, HIGH); 
Serial.begin(9600);
 

//digitalWrite(m12, LOW);
//digitalWrite(m11,LOW);
//digitalWrite(m10, LOW);
//digitalWrite(m9, LOW);
}

void loop() {

  if (Serial.available())
  {
     x=Serial.read();
    if (x == '1') // При получении символа "W" движемся вперед
    {
 analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, LOW);
       digitalWrite(m2, HIGH);
delay(1000);
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
analogWrite(v1, 0);
  analogWrite(v2, 0);
    }
  

else if (x=='2'){
 analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m2, LOW);
       digitalWrite(m1, HIGH);
delay(1000);
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
analogWrite(v1, 0);
  analogWrite(v2, 0);
  }

else if (x=='3'){
 analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, LOW);
       digitalWrite(m2, LOW);
delay(1000);
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
analogWrite(v1, 0);
  analogWrite(v2, 0);
  }

else if(x=='4'){
    analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, HIGH);
       digitalWrite(m2, HIGH);
delay(1000);
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
analogWrite(v1, 0);
  analogWrite(v2, 0);
    }

else  {
//x=0;
digitalWrite(m1, LOW);
digitalWrite(m2, LOW);
analogWrite(v1, 0);
  analogWrite(v2, 0);

}
Serial.println(x);
  }
  
}
