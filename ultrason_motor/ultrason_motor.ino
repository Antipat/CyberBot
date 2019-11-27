int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 = 5;
int trig = 12;    
int echo = 13;  
long dur, cm;

void setup() {
Serial.begin (9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
 pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
}
void loop(){
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
delay(300);

if ( cm>=30 ){
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, LOW);
       digitalWrite(m2, HIGH);
      }
else{ 
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, LOW);
       digitalWrite(m2, LOW);
      }
     }
  
