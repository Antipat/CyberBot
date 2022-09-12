int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 = 5;

void setup()
{
  pinMode(m1,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
}

void loop() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(v1, 255);
  analogWrite(v2, 127);
  delay(3000);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  delay(1000);

  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(v1, 240);
  analogWrite(v2, 80);
  delay(1000);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  delay(1000);

  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(v1, 240);
  analogWrite(v2, 60);
  delay(3000);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  delay(1000);


  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(v1, 250);
  analogWrite(v2, 50);
  delay(3000);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  delay(1000);
    

  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(v1, 250);
  analogWrite(v2, 25);
  delay(3000);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  delay(1000);


digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  analogWrite(v1, 100);
  analogWrite(v2, 100);
  delay(3000);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  delay(1000);
}
