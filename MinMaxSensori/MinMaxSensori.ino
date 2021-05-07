#include <Arduino.h>

int posPollice;
int posIndice;
int posMedio;
int posAnulare;
int posMignolo;
int maxPollice = 0;
int maxIndice  = 0;
int maxMedio  = 0;
int maxAnulare  = 0;
int maxMignolo  = 0;
int minPollice  = 1024;
int minIndice  = 1024;
int minMedio  = 1024;
int minAnulare  = 1024;
int minMignolo = 1024;


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
  if(posPollice<minPollice){
    minPollice = posPollice;
  }
  if(posIndice<minIndice){
    minIndice = posIndice;
  }
  if(posIndice<minIndice){
    minIndice = posIndice;
  }
  if(posMedio<minMedio){
    minMedio = posMedio;
  }
  if(posAnulare<minAnulare){
    minAnulare = posAnulare;
  }
  if(posMignolo<minMignolo){
    minMignolo = posMignolo;
  }

  if(posPollice>maxPollice){
    maxPollice = posPollice;
  }
  if(posIndice>maxIndice){
    maxIndice = posIndice;
  }
  if(posIndice>maxIndice){
    maxIndice = posIndice;
  }
  if(posMedio>maxMedio){
    maxMedio = posMedio;
  }
  if(posAnulare>maxAnulare){
    maxAnulare = posAnulare;
  }
  if(posMignolo>maxMignolo){
    maxMignolo = posMignolo;
  }
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
  Serial.print(posMignolo);
  Serial.print(",");
  Serial.print("maxPollice:");
  Serial.print(maxPollice);
  Serial.print(",");
  Serial.print("maxIndice:");
  Serial.print(maxIndice);
  Serial.print(",");
  Serial.print("maxMedio:");
  Serial.print(maxMedio);
  Serial.print(",");
  Serial.print("maxAnulare:");
  Serial.print(maxAnulare);
  Serial.print(",");
  Serial.print("maxMignolo:");
  Serial.print(maxMignolo);
  Serial.print(",");
  Serial.print("minPollice:");
  Serial.print(minPollice);
  Serial.print(",");
  Serial.print("minIndice:");
  Serial.print(minIndice);
  Serial.print(",");
  Serial.print("minMedio:");
  Serial.print(minMedio);
  Serial.print(",");
  Serial.print("minAnulare:");
  Serial.print(minAnulare);
  Serial.print(",");
  Serial.print("minMignolo:");
  Serial.println(minMignolo);
  delay(100);

}
