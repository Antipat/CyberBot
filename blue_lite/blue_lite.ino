int x;
int ser_en = A4;

void setup()
{
pinMode(ser_en, OUTPUT);
digitalWrite(ser_en, LOW);
delay(1);
digitalWrite(ser_en, HIGH);
Serial.begin(9600);

}

void loop() {
delay(100);

  if (Serial.available())
  {
     x=Serial.read();
     //delay(100);
   
Serial.print(x);
  }
  Serial.println("");
}
