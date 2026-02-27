int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 = 5;

void setup() {
  Serial.begin(9600); // Инициализация порта
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Читаем до новой строки
  
  if (command == "1")
  {
    analogWrite(v2, 0);
    analogWrite(v1, 50);    
    digitalWrite(m1, HIGH);
    delay(20);
    analogWrite(v1, 0); 
    delay(1);   
    }
   else if (command == "2")
  {
    analogWrite(v1, 0);
    analogWrite(v2, 50);    
    digitalWrite(m2, LOW);
    delay(20);
    analogWrite(v2, 0); 
    delay(1);   
    }
  else if (command == "3") 
  {
    analogWrite(v2, 0);
    analogWrite(v1, 50);    
    digitalWrite(m1, LOW);
    delay(20);
    analogWrite(v1, 0); 
    delay(1);   
    }
  else if (command == "4")
  {
    analogWrite(v1, 0);
    analogWrite(v2, 50);    
    digitalWrite(m2, HIGH);
    delay(20);
    analogWrite(v2, 0); 
    delay(1);   
    }
    
  else if (command == "0")
  {
    analogWrite(v1, 0);
    analogWrite(v2, 0);        
    }
  
  }
  
}
