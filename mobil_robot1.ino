int m1 = 7;
int m2 = 4;

int v1 = 6;
int v2 = 5;

float h= 0.144;
int s= 0;
int s1 = 0;
float l = 155.4;
float n = 1.83;


void setup()
{
  Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
    
}

void loop() {
  
for (int i =126; i<255; i+=13)
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  analogWrite(v1, i);
  analogWrite(v2, i);
  delay(1000);
  s=l*n;
  s1=s1+s;
  n=n+h;

  Serial.print("s1 = ");
  Serial.print(s1);
  Serial.print(" mm ");
  Serial.println("  ");
  }
  analogWrite(v1, 0);
  analogWrite(v2, 0);


    }

    


      
