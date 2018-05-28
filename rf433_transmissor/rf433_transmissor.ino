//Programa : Módulo RF Transmissor com Arduino Uno
//Autor : FILIPEFLOP - Arduino e Cia
 
#include <VirtualWire.h>
 
String mensagem;
 
void setup()
{
  Serial.begin(9600);
  vw_set_tx_pin(8); //Define o pino 8 do Arduino como 
//o pino de dados do transmissor
  vw_setup(2000);   // Bits per sec
}
 
void loop()
{
  char data[30];
  int numero;
  if (Serial.available() > 0)
  {
    numero = Serial.readBytesUntil (13,data,20);
    data[numero] = 0;
    Serial.print("Enviado : ");
    Serial.print(data);
    Serial.print(" - Caracteres : ");
    Serial.println(strlen(data));
    send(data);  //Envia a mensagem para a rotina que
//envia os dados via RF
  }  
} 
 
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Aguarda o envio de dados
}

