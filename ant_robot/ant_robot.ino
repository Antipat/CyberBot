#include <Servo.h> //используем библиотеку для работы с сервоприводом
#include <IRremote.h>

Servo servo; 


int m1 = 7;
int m2 = 4;

int v1 = 6;
int v2 = 5;

int trig = 8;    
int echo = 2;  
long dur, cm;

int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  servo.write(30);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(m1,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v2,OUTPUT);
  servo.attach(12);  
  //analogWrite(v1, 127);
  //analogWrite(v2, 127);
  //digitalWrite(m1, HIGH);
  //digitalWrite(m2, LOW);

  //delay(10510);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  pinMode(trig, OUTPUT);

pinMode(echo, INPUT);

}

void loop() {

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

if ( cm<=15 ){
      servo.write(100);
      }
else{
  
  servo.write(10);
  }
  
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
else if (results.value == 16724175){
      servo.write(30);
      } 

else if (results.value == 16718055){
      servo.write(100);
      } 
       
  }
    }

    


      
