int m1 = 7;
int m2 = 4;
int v1 = 6;
int v2 =  5;

int t = 0;
int s = 0;
float l = 155.43;
float n = 0;


void setup() {
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);

  analogWrite(6, 0);
  analogWrite(5, 0);

for (int i=0; i<5; i++)
{
  digitalWrite(m1,LOW);
digitalWrite(m1,LOW);
analogWrite(6, 127);
 analogWrite(5, 127);
 delay(1000);
 n=n+1.83;
 s=l*n;
 Serial.print("s = ");
 Serial.print(s);
 Serial.print(" mm ");
 Serial.println();
  }
  analogWrite(6, 0);
analogWrite(5, 0);


}

void loop() {
  

}
