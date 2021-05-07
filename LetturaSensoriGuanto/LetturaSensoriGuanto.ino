#include <Arduino.h>

int posPollice;
int posIndice;
int posMedio;
int posAnulare;
int posMignolo;


void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT); 
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

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
  delay(100);

}
