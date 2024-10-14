
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.

#define USE_MATH_DEFINES

iarduino_I2C_Motor mot_Ru(0x10);                    //   Объявляем объект mot для работы с функциями и методами библиотеки iarduino_I2C_Motor, указывая адрес модуля на шине I2C.

iarduino_I2C_Motor mot_L(0x09);                   //   Объявляем объект mot для работы с функциями и методами библиотеки iarduino_I2C_Motor, указывая адрес модуля на шине I2C.
                                               //   Если объявить объект без указания адреса (iarduino_I2C_Motor mot;), то адрес будет найден автоматически.
iarduino_I2C_Motor mot_R(0x0A);                                                   //   Если объявить объект без указания адреса (iarduino_I2C_Motor mot;), то адрес будет найден автоматически.
                                               

float R = 65;   // расстояние от центра тяжести треугольника до рицинуса.
float r = 22.1;  // радиус колеса

float L = 0.0; // переменная Длина дуги поворота
float L1 =0.0; // полный оборот колеса
float ob = 0.0; // кол. об.

float angle =90.0; //угол поворота

int x;


void setup() {
 Serial.begin(9600);                           //
    while(!Serial){;}                             // * Ждём завершения инициализации шины UART.
    mot_L.begin();                                  //   Инициируем работу с мотором.
    mot_L.radius = r;                         //Указываем радиус колеса в мм.
    mot_R.begin();                                  //   Инициируем работу с мотором.
    mot_R.radius = r;                      //   Указываем радиус колеса в мм.
  
     `1mot_Ru.begin();                                  //   Инициируем работу с мотором.
    mot_Ru.radius = r;  
  mot_R.setDirection(false);
  L1 = 2*M_PI*R;                     
  L = (angle/180)*M_PI*R;              // Длина дуги в мм
  ob =6* L/L1;
  L = L/1000; 
  
  
// обнуление
  mot_R.delSum();
 
   delay(250);
}

void loop() {

  if (Serial.available())
  {
     x=Serial.read();
    if (x == 'w') // При получении символа "W" движемся вперед
    {
  mot_R.delSum();
  mot_R.setSpeed(-50, MOT_PWM, 0.15, MOT_MET); 
  mot_L.setSpeed(50, MOT_PWM, 0.15, MOT_MET);
  delay(3000);
  mot_R.setStop(); 
  mot_L.setStop();
    }
  

  else if (x=='s'){
  mot_R.delSum();
  mot_R.setSpeed(50, MOT_PWM, 0.15, MOT_MET); 
  mot_L.setSpeed(-50, MOT_PWM, 0.15, MOT_MET);
  delay(3000);
  mot_R.setStop(); 
  mot_L.setStop();
  }

  else if (x=='a'){
  mot_Ru.delSum();
  mot_Ru.setSpeed(100, MOT_PWM, 0.05, MOT_MET);  
  delay(2000);
  mot_Ru.setStop();  
  }
 else if (x=='d'){
  mot_Ru.delSum();
  mot_Ru.setSpeed(-100, MOT_PWM, 0.05, MOT_MET);  
  delay(2000);
  mot_Ru.setStop();  
  }

   else if (x=='p'){
  mot_R.setStop(); 
  mot_L.setStop();
  mot_Ru.setStop();  
  }

Serial.println(x);
  }
  
}
