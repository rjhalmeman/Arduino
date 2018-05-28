//Programa : Receptor RF com Arduino Mega e Display Nokia 5110
//Autor : Arduino e Cia


#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens

void setup()   {
  Serial.begin(9600);
  vw_set_rx_pin(5); // Define o pino 5 do Arduino como entrada do pino de dados do receptor
  vw_setup(2000);             // Bits por segundo
  vw_rx_start();              // Inicializa o receptor


  delay(2000);

}

int led = 13; 
int j=0;
boolean v=true;

void loop()
{
  uint8_t message[VW_MAX_MESSAGE_LEN];    
  uint8_t msgLength = VW_MAX_MESSAGE_LEN; 

  if (v){
    digitalWrite(led, HIGH);
    v = !v;
  } 
  else {
    digitalWrite(led, LOW);
  }
  delay(1000);

  if (vw_get_message(message, &msgLength)) // Non-blocking
  {
    for (j=1;j<30;j++){
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(10);               // wait for a second
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      delay(10);               // wait for a second
    }
  }
}



