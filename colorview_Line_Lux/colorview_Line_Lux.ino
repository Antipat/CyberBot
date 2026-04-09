#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define redpin 13
#define greenpin 12
#define bluepin 8

// set to false if using a common cathode LED
#define commonAnode true

// our RGB -> eye-recognized gamma color
byte gammatable[256];

// первый датчик
int color = 10;
int svet = 11;

// второй датчик
int color1 = 9;
int svet1 = 3;

// переключение датчиков
bool key = false;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// моторы
int m1 = 7;
int m2 = 4;

int v1 = 6;
int v2 = 5;

float SA;
float SSA;
// счётчик
int n = 0;
// коэффициент отклонения
int k = 2;

// Константы калибровки
float sLux = 0.0;
float sSLux = 0.0;

void setup() {
  // включаем первый датчик 
 pinMode(color, OUTPUT);
 pinMode(svet, OUTPUT);
 digitalWrite(svet, HIGH);
 digitalWrite(color, HIGH);

  Serial.begin(115200);  

  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
 // включаем второй датчик 
 pinMode(color1, OUTPUT);
 pinMode(svet1, OUTPUT);
 digitalWrite(svet1, HIGH);
 digitalWrite(color1, HIGH);

  Serial.begin(115200);
  //Serial.println("Color View Test!");

  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }

  
#if defined(ARDUINO_ARCH_ESP32)
  ledcAttachPin(redpin, 1);
  ledcSetup(1, 12000, 8);
  ledcAttachPin(greenpin, 2);
  ledcSetup(2, 12000, 8);
  ledcAttachPin(bluepin, 3);
  ledcSetup(3, 12000, 8);
#else
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
#endif

  // thanks PhilB for this gamma table!
  // it helps convert RGB colors to what humans see
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;
    }
    //Serial.println(gammatable[i]);
  }
  // назначаем пины моторам
  pinMode(m1,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v2,OUTPUT);
  
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  delay(1000);
  analogWrite(v1, 0);
  analogWrite(v2, 0);

  delay(2000);
  
}

// The commented out code in loop is example of getRawData with clear value.
// Processing example colorview.pde can work with this kind of data too, but It requires manual conversion to 
// [0-255] RGB value. You can still uncomments parts of colorview.pde and play with clear value.
void loop() {
    float red, green, blue;
  
  tcs.setInterrupt(false);  // turn on LED

  delay(1);  // takes 50ms to read

  tcs.getRGB(&red, &green, &blue); 

  Serial.print("\n");


#if defined(ARDUINO_ARCH_ESP32)
  ledcWrite(1, gammatable[(int)red]);
  ledcWrite(2, gammatable[(int)green]);
  ledcWrite(3, gammatable[(int)blue]);
#else
  analogWrite(redpin, gammatable[(int)red]);
  analogWrite(greenpin, gammatable[(int)green]);
  analogWrite(bluepin, gammatable[(int)blue]);
#endif

float r = int(red); // /255.0;
float g = int(green);  // /255.0;
float b = int(blue);  //255.0;

if (key == false){
  SA = tcs.calculateLux(r, g, b); 
  digitalWrite(color, HIGH);
  digitalWrite(color1, LOW);
  }

else {
  SSA = tcs.calculateLux(r, g, b);  
  digitalWrite(color, LOW);
  digitalWrite(color1, HIGH);
 }
delay(10);
// переключение
key = !key;

// константа для второго датчика
if (n==5)
{
  sSLux = tcs.calculateLux(r, g, b);  
 }
 // константа для первого датчика
 if (n==4)
{
  sLux = tcs.calculateLux(r, g, b); 
 }
 
// отсчёт
n+=1;

if (n>10)
{
  n = 10;
  }

// алгоритм движения
if (n ==10)
{
  if(((SA  > sLux-k)&& (SA  < sLux+k))&& ((SSA > sSLux-k)&&(SSA < sSLux+k)) )
  {
   
    analogWrite(v1, 35);
    analogWrite(v2, 35);
    digitalWrite(m2, LOW);
    digitalWrite(m1, HIGH);
    }
  
   if(SA >= sLux+k)
   {
     if(SSA <= sSLux+k){
    analogWrite(v1, (int)SA);
    analogWrite(v2, (int)SA);
    digitalWrite(m2, HIGH);
    digitalWrite(m1, HIGH);    
   delay(2);
     }
     
    }
   
   if(SSA >= sSLux+k)
   {
    if(SA <= sLux+k){
    digitalWrite(m2, LOW);
    digitalWrite(m1, LOW);    
    analogWrite(v1, (int)SSA);
    analogWrite(v2, (int)SSA);      
    delay(2);
    }
    }
   }     
   
    Serial.println();
     Serial.print("\tsH:\t"); Serial.print(SA); 
    Serial.print("\tsS:\t"); Serial.print(SSA); 
    Serial.print("\tsL:\t"); Serial.print(sLux); 
     Serial.print("\tsSL:\t"); Serial.print(sSLux); 
  
  //delay(50);
//Serial.print("key = ");
//Serial.print( key);
}
