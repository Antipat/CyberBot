int l1 =11;
int l2 =10;

void setup() {
 pinMode(l1,INPUT);
pinMode(l2,INPUT);
Serial.begin(9600);
}

void loop() {
  
  //Serial.println("left_line");
  //Serial.println(digitalRead(l1));
  
  Serial.println("right_line");
  Serial.println(digitalRead(l2));
 
delay(500);
}
