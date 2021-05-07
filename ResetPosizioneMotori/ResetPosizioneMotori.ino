#include <Servo.h> //Includes servo library

Servo finger1, finger2, finger3, finger4, finger5;

int servoPin1 = 5;
int servoPin2 = 6;
int servoPin3 = 9;
int servoPin4 = 10;
int servoPin5 = 3;


void setup()
{
  //Attach the servo objects to their respective pins
  finger1.attach(servoPin1);
  finger2.attach(servoPin2);
  finger3.attach(servoPin3);
  finger4.attach(servoPin4);
  finger5.attach(servoPin5);
}

void loop()
{   
    int flex1 = 0;
    int flex2 = 0;
    int flex3 = 0;
    int flex4 = 0;
    int flex5 = 0;
    finger1.write(flex1);
    finger2.write(flex2);
    finger3.write(flex3);
    finger4.write(flex4);
    finger5.write(flex5);
   
}
