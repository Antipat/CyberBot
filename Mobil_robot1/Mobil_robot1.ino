int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 =  5;


void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);

  analogWrite(6, 0);
  analogWrite(5, 0);

}

void loop() {
  
digitalWrite(m1,LOW);
//digitalWrite(m1,LOW);
analogWrite(6, 100);
 analogWrite(5, 100);
 delay(1000);
 
digitalWrite(m1,HIGH);
//digitalWrite(m1,LOW);
analogWrite(6, 100);
 analogWrite(5, 100);
 delay(1000);
 
}
