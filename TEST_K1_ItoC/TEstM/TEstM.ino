// ДАННЫЙ ПРИМЕР ЗАПУСКАЕТ МОТОР С УКАЗАНИЕМ ШИМ: // * Строки со звёздочкой являются необязательными.
                                                  //
                                               //
#include <Wire.h>                                 //   Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки KLIK_I2C_Motor.
#include <KLIK_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
KLIK_I2C_Motor motl(0x0B);                     //   Объявляем объект mot для работы с функциями и методами библиотеки KLIK_I2C_Motor, указывая адрес модуля на шине I2C.
KLIK_I2C_Motor motr(0x0A);                                                   //   Если объявить объект без указания адреса (KLIK_I2C_Motor mot;), то адрес будет найден автоматически.

#include <IRremote.h>

int RECV_PIN = 3;
int m1 = 4;
int m2 = 7;
int v1 = 6;
int v2 = 5;

byte x = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup(){ 
	Serial.begin(9600); 
    while(!Serial){;}                                //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    motl.begin(&Wire); // &Wire1, &Wire2 ...       //   Инициируем работу с мотором, указав ссылку на объект для работы с шиной I2C на которой находится мотор (по умолчанию &Wire).
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    motr.begin(&Wire); // &Wire1, &Wire2 ...

  irrecv.enableIRIn(); // Start the receiver
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(v1,OUTPUT);
  pinMode(v2,OUTPUT);
  analogWrite(v1, 0);
  analogWrite(v2, 0);

Wire.begin();
}                                                 //
                                                  //
void loop(){                                      //
    

  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    //Serial.println(results.value);
    //irrecv.resume(); 

    if (results.value == 16720605){
      analogWrite(v1, 255);
      analogWrite(v2, 255);
      digitalWrite(m1, LOW);
       digitalWrite(m2, HIGH);
      }
    else if (results.value == 16761405){
      analogWrite(v1, 0);
      analogWrite(v2, 0);
      } 
    else if (results.value == 16712445){
      analogWrite(v1, 255);
      analogWrite(v2, 255);
      digitalWrite(m1, HIGH);
       digitalWrite(m2, LOW);
      }
    else if (results.value == 16753245){
      analogWrite(v1, 255);
      analogWrite(v2, 255);
      digitalWrite(m1, HIGH);
       digitalWrite(m2, HIGH);
      }
     else if (results.value == 16769565){
      analogWrite(v1, 255);
      analogWrite(v2, 255);
      digitalWrite(m1, LOW  );
       digitalWrite(m2, LOW);
      } 
      else if (results.value == 16769055){
      // -
      motl.setSpeed(  50.0, MOT_PWM);                //   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
      Serial.print("Скорость L ");
      Serial.println(50.0);
      } 
      else if (results.value == 16754775){
      // +
      motr.setSpeed(  50.0, MOT_PWM);                //   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
      Serial.print("Скорость R ");
      Serial.println(50.0);
      } 
      else if (results.value == 16738455){
      // 0
      motl.setSpeed( 0.0, MOT_PWM);                //   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
      motr.setSpeed( 0.0, MOT_PWM);
      Serial.print("Скорость STOP ");
     Serial.println(0.0);
      } 

      else if (results.value == 16724175){
       Wire.beginTransmission(8); // transmit to device #8
      x = 10;
      //Wire.write("x is ");        // sends five bytes
      Wire.write(x);              // sends one byte
      Wire.endTransmission(); 
      } 
      else if (results.value == 16718055){
      Wire.beginTransmission(8); // transmit to device #8
      x = 50;
      //Wire.write("x is ");        // sends five bytes
      Wire.write(x);              // sends one byte
      Wire.endTransmission();
      } 
      else if (results.value == 16743045){
      Wire.beginTransmission(8); // transmit to device #8
      x = 100;
      //Wire.write("x is ");        // sends five bytes
      Wire.write(x);              // sends one byte
      Wire.endTransmission();
      } 
      else if (results.value == 16716015){
      Wire.beginTransmission(8); // transmit to device #8
      x = 150;
      //Wire.write("x is ");        // sends five bytes
      Wire.write(x);              // sends one byte
      Wire.endTransmission();
      } 
      else if (results.value == 16726215){
      Wire.beginTransmission(8); // transmit to device #8
      x = 200;
      //Wire.write("x is ");        // sends five bytes
      Wire.write(x);              // sends one byte
      Wire.endTransmission();
      } 
      else if (results.value == 16734885){
      Wire.beginTransmission(8); // transmit to device #8
      x = 0;
      //Wire.write("x is ");        // sends five bytes
      Wire.write(x);              // sends one byte
      Wire.endTransmission();
      }
           
    irrecv.resume(); 
  Serial.println(results.value);
  }                     
}                                                
