// ДАННЫЙ ПРИМЕР ЗАПУСКАЕТ МОТОР С УКАЗАНИЕМ ШИМ: // * Строки со звёздочкой являются необязательными.
                                                  //
                                               //
#include <Wire.h>                                 //   Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки KLIK_I2C_Motor.
#include <KLIK_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
KLIK_I2C_Motor motl(0x08);                     //   Объявляем объект mot для работы с функциями и методами библиотеки KLIK_I2C_Motor, указывая адрес модуля на шине I2C.
KLIK_I2C_Motor motr(0x09);                                                   //   Если объявить объект без указания адреса (KLIK_I2C_Motor mot;), то адрес будет найден автоматически.
KLIK_I2C_Motor motrr(0x10);   

int m1 = 4;
int m2 = 7;
int v1 = 6;
int v2 = 5;

int n;

void setup(){
  digitalWrite(A4, LOW);
  delay(10);
  digitalWrite(A4, HIGH);
	Serial.begin(9600); 
    while(!Serial){;}                                //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    motl.begin(&Wire); // &Wire1, &Wire2 ...       //   Инициируем работу с мотором, указав ссылку на объект для работы с шиной I2C на которой находится мотор (по умолчанию &Wire).
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    motr.begin(&Wire); // &Wire1, &Wire2 ...
   delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    motrr.begin(&Wire); // &Wire1, &Wire2 ...
    
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);
  
 Wire.begin(8);                // join i2c bus with address #8
 //Wire.onReceive(receiveEvent)
}                                                 //
void receiveEvent(int howMany) {
  if (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  n = Wire.read();    // receive byte as an integer
  Serial.println(n);
  return;
  } 
  
void loop(){ 
  Wire.onReceive(receiveEvent);     
  if (n == 0){
      analogWrite(v1, 0);
      analogWrite(v2, 0);
      motl.setSpeed( 0.0, MOT_PWM);                //   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
      motr.setSpeed( 0.0, MOT_PWM);                   
      motrr.setSpeed( 0.0, MOT_PWM);
      digitalWrite(m1, LOW);
       digitalWrite(m2, HIGH);
      }
    else if (n == 10){
      analogWrite(v1, 100);
      analogWrite(v2, 100);      
      digitalWrite(m1, LOW);
       digitalWrite(m2, HIGH);
      } 
    else if (n == 50){
      analogWrite(v1, 255);
      analogWrite(v2, 255);
      digitalWrite(m1, HIGH);
       digitalWrite(m2, LOW);
      }
    else if (n == 100){      
      motl.setSpeed( 50.0, MOT_PWM);                //   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
      motr.setSpeed( 50.0, MOT_PWM);                   
      motrr.setSpeed( 50.0, MOT_PWM);
     
      }
     else if (n == 150){
       motl.setSpeed( -50.0, MOT_PWM);                //   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
      motr.setSpeed( 50.0, MOT_PWM);                   
      motrr.setSpeed( -50.0, MOT_PWM);
      } 
      else if (n == 200){
      // -
       motl.setSpeed( -100.0, MOT_PWM);                //   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
      motr.setSpeed( -100.0, MOT_PWM);                   
      motrr.setSpeed( -100.0, MOT_PWM);
      }     
  delay(100);            
}                                                
