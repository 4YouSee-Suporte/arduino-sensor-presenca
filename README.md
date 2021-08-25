
<h1>Arduino com Sensor de Presença</h1>
O arduino usado nesse projeto é um arduino leonardo pois através dele é possível tomar controle do teclado e mouse para agir como eles uma vez esteja conectado ao computador. No caso do sensor de presença, foi usado um sensor PIR DYP-ME003. Ambos foram conectados conforme a seguinte imagem:

<h4 align="center">
  <img src="https://user-images.githubusercontent.com/63620799/130868795-c0e2b974-87e6-4ab7-9b91-288418c29737.png">
</h4>

<h1 align="center"> 
	🚧 Código Fonte
</h1>
O Arquivo com o código se encontra aqui:

📥 [Baixar Arquivo Fonte para Sensor PIR](https://github.com/4YouSee-Suporte/arduino-sensor-presenca/blob/main/proximidade.ino) 

A continuação iremos explicar como funciona esse arquivo, lembrando que ele deve ser montado a través do programa do arduino no aparelho (arduino leonardo) que você tenha :


```
#include <Keyboard.h>
#define pinPIR 7 // O cabo é conectado no PIN 7 (Pode ser qualquer outro)
int pointer;

void setup() {
  Serial.begin(9600);  // Inicialização da conexão
  pinMode(pinPIR, INPUT);
  Keyboard.begin();
}

void loop() {
  /*
   * O valor entregue pelo sensor ao arduino vem em inteiro determinando dessa forma um valor x quando ele deteta e quando não o valor será menor.
   * O valor entregue pelo sensor vai depender de como está ele calibrado físicamente. Podendo determinar a sensibilidade da deteção e o tempo que ele envia
   * os dados ao arduino após primeira deteção.
   */
  int valorPIR = digitalRead(pinPIR);
  if (valorPIR && pointer >= 30){ 
  // Se o valor valorPIR que é o valor entregue pelo sensor ao Arduino, e o pointer são maiores que 30, então vai enviar o número 11 como se o arduino fosse um teclado.
    Serial.println("DETECTADO");
    Keyboard.print("11\n");
    pointer = 0;
  // Depois que deteta um movimento ele zera o pointer, deixando claro que cada vez que o pointer tenha o valor em 0 é porque já detetou movimento alguma vez.
  } else {
  // Se não deteta movimento a cada meio segundo então o pointer vai aumentar.
  // Isto ajuda em que o sensor não mande a sinal ao teclado a cada meio segundo se houvesse movimentos a cada meio segundo, se não após alcançar o 30, ou seja após 15 segundos.
    Serial.println("SIN DETECCIÓN");
    pointer += 1;
  }
  Serial.println("----------------------");
  delay(500); // A leitura é executada a cada 500 milisegundos (meio segundo) (2 veces por segundo)
}
```

<h1 align="center"> 
	🚀 Como usar com o 4YouSee Player
</h1>
Quando já foi implementado o paso anterior e o arduino está lendo a presença e enviando o número 11 ao computedor como se fosse um teclado, você pode revisar o repositório:

> Repositório: [4YouSee Sensors](https://github.com/4YouSee-Suporte/4yousee-sensors)

Nele você encontrará a possibilidade de receber comandos para que o player execute conteúdos a partir daqueles comandos recebidos que no caso do sensor de presença, ele envia o número 11.

O 4YouSee Sensors nada mais é do que um script que roda em background no mesmo computador onde deve estar o 4yousee player instalado e fica escutando o que for digitado para dessa forma exiba o conteúdo no player um por vez.

