#include <Servo.h>

Servo finger1,finger2,finger3,finger4,finger5;
int servo1 = 3;
int servo2 = 5;
int servo3 = 6;
int servo4 = 9;
int servo5 = 10;

void setup(){
  Serial.begin(115200);
  finger1.attach(servo1);
  finger2.attach(servo2);
  finger3.attach(servo3);
  finger4.attach(servo4);
  finger5.attach(servo5);
  
}

void loop(){
  for(int i = 0; i < 150; i++){
    finger1.write(i);
    finger2.write(i);
    finger3.write(i);
    finger4.write(i);
    finger5.write(i);
    Serial.print(i);
    Serial.println(",");
    delay(10);
  }
  for(int i = 149; i >= 0; i--){
    finger1.write(i);
    finger2.write(i);
    finger3.write(i);
    finger4.write(i);
    finger5.write(i);
    Serial.print(i);
    Serial.println(",");
    delay(10);
  }
}
