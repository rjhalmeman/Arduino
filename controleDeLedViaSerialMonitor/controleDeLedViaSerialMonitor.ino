int pinoLed = 13;
int estadoLed=0;

void setup(){
  Serial.begin(9600);
  pinMode(pinoLed,OUTPUT);
}

void loop(){
  if (Serial.available()){
    estadoLed = Serial.read();
    if (estadoLed == 49){ //1
      digitalWrite(pinoLed, HIGH);
      Serial.println(estadoLed);

    } 
    if (estadoLed ==48) { //0 (zero)
      digitalWrite(pinoLed, LOW);
      Serial.println(estadoLed);
    } 
  }
}

