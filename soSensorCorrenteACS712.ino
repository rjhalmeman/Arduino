void setup() {
  // inicializa a comunicação seral a 9600 bits por segundo:
  Serial.begin(9600);
}

void loop() {
  // leitura input no analog pin 0:

  //aqui a leitura é mostrada entre 0 e 1023
  double sensorValue = analogRead(A0);

  //podemos fazer transformações para mostrar em Amperes

  //O código a seguir diz para o Arduino que o valor lido pelo sensor deve ser transformado de 0 a 1023 para -30 a +30.

  double outputValue = map(sensorValue, 0, 1023, -30, 30);
  // mostrar valor lido pelo sensor:

  Serial.print("Sensor corrente: ");

  Serial.print(sensorValue);

  //mostrar valor transformado em amperes:

  Serial.print("  Valor em Amperes: ");

  Serial.println(outputValue);

  delay(1000); // Tempo entre leituras
}

