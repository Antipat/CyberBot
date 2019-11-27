int m1 = 13;
int m2 = 11;
int v1 = 9;
int v2 = 7;

int trig = 5;    
int echo = 3;  
long dur, cm;

void setup() {

Serial.begin (9600);

pinMode(trig, OUTPUT);

pinMode(echo, INPUT);

 pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
  //analogWrite(v1, 0);
 // analogWrite(v2, 0);


}
void loop(){

// Датчик генерирует импульсы шириной 10 мкс
// Генерируем короткий LOW импульс, чтобы обеспечить хороший импульс HIGH:

digitalWrite(trig, LOW);

delayMicroseconds(5);

digitalWrite(trig, HIGH);

delayMicroseconds(10);

digitalWrite(trig, LOW);

// Считываем данные с ультразвукового датчика: значение HIGH, которое

// зависит от длительности (в микросекундах) между отправкой

// акустической волны и ее обратном приеме на эхолокаторе.

pinMode(echo, INPUT);

dur = pulseIn(echo, HIGH);

cm = (dur/2) / 29.1;

Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(300);

if ( cm>=45 ){
      digitalWrite(v1, LOW);
       digitalWrite(v2, HIGH);
      digitalWrite(m1, LOW);
       digitalWrite(m2, HIGH);
      }
else{ 
         digitalWrite(v1, LOW);
       digitalWrite(v2, HIGH);
      digitalWrite(m1, HIGH);
       digitalWrite(m2, LOW);
      }
  
  
  }
