int pulsador = 2; // pin boton de encendido y apagado

void setup(){
   pinMode(Led,OUTPUT);
  pinMode(pulsador, INPUT);
}

void loop(){
  while(digitalRead(pulsador)==LOW);
  digitalWrite(Led, HIGH);
  while(digitalRead(pulsador)==HIGH);
}
