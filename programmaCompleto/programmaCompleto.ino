#include <Servo.h>
#include <Arduino.h>

int posPollice;
int posIndice;
int posMedio;
int posAnulare;
int posMignolo;

Servo srvPollice,srvIndice,srvMedio,srvAnulare,srvMignolo;

int pinPollice = 10;
int pinIndice = 6;
int pinMedio = 9;
int pinAnulare = 3;
int pinMignolo = 5;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT); 
  pinMode(A3, INPUT);
  pinMode(A4, INPUT); 
  srvPollice.attach(pinPollice);
  srvIndice.attach(pinIndice);
  srvMedio.attach(pinMedio);
  srvAnulare.attach(pinAnulare);
  srvMignolo.attach(pinMignolo);


}

void loop() {
   
  posPollice = analogRead(A0);
  posIndice = analogRead(A1);
  posMedio = analogRead(A2);
  posAnulare = analogRead(A4);
  posMignolo = analogRead(A3);
  
  Serial.print("Pollice:");
  Serial.print(posPollice);
  Serial.print(",");
  Serial.print("Indice:");
  Serial.print(posIndice);
  Serial.print(",");
  Serial.print("Medio:");
  Serial.print(posMedio);
  Serial.print(",");
  Serial.print("Anulare:");
  Serial.print(posAnulare);
  Serial.print(",");
  Serial.print("Mignolo:");
  Serial.println(posMignolo);

  int posServo1 = map(posPollice, 750, 850, 0, 180);
  posServo1 = constrain(posServo1, 0, 180);
  int posServo2 = map(posIndice, 550, 900, 0, 180);
  posServo2 = constrain(posServo2, 0, 180);
  int posServo3 = map(posMedio, 500, 850, 0, 180);
  posServo3 = constrain(posServo3, 0, 180);
  int posServo4 = map(posAnulare, 550, 900, 0, 180);
  posServo4 = constrain(posServo4, 0, 180);
  int posServo5 = map(posMignolo, 550, 900, 0, 180);
  posServo5 = constrain(posServo5, 0, 180);

  srvPollice.write(posServo1);
  srvIndice.write(posServo2);
  srvMedio.write(posServo3);
  srvAnulare.write(posServo4);
  srvMignolo.write(posServo5);
  delay(50);

}
