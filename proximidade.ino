#include <Keyboard.h>
#define pinPIR 7
int pointer;

void setup() {
  Serial.begin(9600);  
  pinMode(pinPIR, INPUT);
  Keyboard.begin();
}

void loop() {
  int valorPIR = digitalRead(pinPIR);
  if (valorPIR && pointer >= 30){
    Serial.println("DETECTADO");
    Keyboard.print("11\n");
    pointer = 0;
  } else {
    Serial.println("SIN DETECCIÓN");
    pointer += 1;
  }
  Serial.println("----------------------");
  delay(500);
}
