
int x;
int m1 = 7;
int v1 = 6;
int m2 = 4;
int v2 = 5;

int ser_en = A4;
// кодировка символов

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int xVal = -2000;
int yVal = -2000;
String sXVal = "";
String sYVal = "";

bool bObjectFound = false;
bool bTurningLeftLast = false;
bool bTurningRightLast = false;


void setup() {
pinMode(ser_en, OUTPUT);
digitalWrite(ser_en, LOW);
delay(1);
digitalWrite(ser_en, HIGH);

pinMode(m1, OUTPUT);
pinMode(v1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(v2,OUTPUT);
analogWrite(v1,0);
Serial.begin(9600);
digitalWrite(m1, LOW);

}
void loop() {
//delay(100);
  if (Serial.available())
  {
     x=Serial.read();

    
    
//Serial.println(x);
//Serial.print((char)x);
  inputString += (char)x;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if ((char)x == '\n') {
      stringComplete = true;
      //Serial.flush();
  }


if (stringComplete) {
  
    //Serial.flush(); // To avoid too much buffer building up whilst processing below:
    
    if (inputString.startsWith("CO:0:"))
    {
      //Serial.println(inputString);
      inputString.replace("CO:0:", "");
      //Serial.println(inputString);
      int commaPos = inputString.indexOf(",");
      if (commaPos>0)
      {
        sXVal = inputString.substring(0, commaPos);
        xVal = sXVal.toInt();
        Serial.print("x= ");
        Serial.print(xVal);
        int commaPos2 = inputString.indexOf(",", commaPos+1);
        sYVal = inputString.substring(commaPos+1, commaPos2);
        yVal = sYVal.toInt();
        Serial.print(" y= ");
        Serial.print(yVal);
        Serial.println("");

        if(yVal>=-75 && yVal<=75){
        if (xVal>=-75 && xVal<=75)
        {
          analogWrite(v1,0);
          analogWrite(v2,0);
          digitalWrite(m1, LOW);
          digitalWrite(m2, LOW);
        }
        if (xVal<-300 || xVal>300)
        {
          analogWrite(v1,0);
          analogWrite(v2,0);
          digitalWrite(m1, LOW);
          digitalWrite(m2, LOW);
        }
        if (xVal>=-300&& xVal<=-75)
        {
          analogWrite(v1,100);
          analogWrite(v2,100);
          digitalWrite(m1, LOW);
          digitalWrite(m2, HIGH);
          delay(15);
          analogWrite(v1,0);
          analogWrite(v2,0);
          delay(10);
        }
        if ((xVal>=75 && xVal<=300))
        {
          analogWrite(v1,100);
          analogWrite(v2,100);
          digitalWrite(m1, HIGH);
          digitalWrite(m2, LOW);
          delay(15);
          analogWrite(v1,0);
          analogWrite(v2,0);
          delay(10);
        }
        }
        if (yVal>75 && yVal<=175)
        {
          analogWrite(v1,100);
          analogWrite(v2,100);
          digitalWrite(m1, LOW);
          digitalWrite(m2, LOW);
          delay(15);
          analogWrite(v1,0);
          analogWrite(v2,0);
          delay(10);
        }
        if (yVal<-75 && yVal>=-175)
        {
          analogWrite(v1,100);
          analogWrite(v2,100);
          digitalWrite(m1, HIGH);
          digitalWrite(m2, HIGH);
          delay(15);
          analogWrite(v1,0);
          analogWrite(v2,0);
          delay(10);
        }
      } 
    
  }  
  inputString = "";
  stringComplete = false;
}
}
}
