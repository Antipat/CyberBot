int l1 =11;
int l2 =10;

int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 = 5;

void setup() {
 pinMode(l1,INPUT);
pinMode(l2,INPUT);
pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  
Serial.begin(9600);
}

void loop() {
   if ( digitalRead(l1)== 0 && digitalRead(l2)== 0 ){
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, LOW);
       digitalWrite(m2, HIGH);
      }
    else if ( digitalRead(l1)== 1 && digitalRead(l2)== 0 ){
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, HIGH);
       digitalWrite(m2, HIGH);
      }

       else if ( digitalRead(l1)== 0 && digitalRead(l2)== 1 ){
      analogWrite(v1, 100);
      analogWrite(v2, 100);
      digitalWrite(m1, LOW);
       digitalWrite(m2, LOW);
      }
      else
      {
        analogWrite(v1, 0);
      analogWrite(v2, 0);
      digitalWrite(m1, LOW);
       digitalWrite(m2, LOW);
      }
        
  Serial.println("left_line");
  Serial.println(digitalRead(l1));
  
  Serial.println("right_line");
  Serial.println(digitalRead(l2));
 
delay(500);
}
