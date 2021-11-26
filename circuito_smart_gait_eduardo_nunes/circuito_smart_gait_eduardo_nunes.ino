

// AUTOR: EDUARDO ELIAS NUNES 

// CIRCUITO LIGA/DESLIGA LED COM RELÉ ACIONADO VIA BLUET00TH POR UMA PLACA ESP32.

#include "BluetoothSerial.h"
#define PINLED 2

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); 
  pinMode(PINLED,OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char leitura = SerialBT.read();
    if(leitura == '1'){
      digitalWrite(PINLED, HIGH);
    }
    else if (leitura == '0'){
      digitalWrite(PINLED, LOW);
    }
  }
}
