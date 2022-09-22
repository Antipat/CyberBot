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
  
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
}

void loop() {
  
  analogWrite(v1, 100);
  analogWrite(v2, 100);
  delay(10);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  delay(500);

    }
    


    
