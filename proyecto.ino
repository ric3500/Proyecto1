int Led = 4; //pin led de encendido de alarma
int Led1 = 5; //pin luces delanteras y traseras
int pulsador = 2; // pin boton de encendido y apagado
int compuerta = 9; // pin lectura del estado de la puerta
int compuerta1 = 6; // pin led de notificacion de puerta abierta
int speak = 8; // pin del sumbador
float sinval; //valor flotante para convercion
int toneval; // guarda el valor que tiene que tener tono

void setup(){
  pinMode(Led,OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(pulsador, INPUT);
  pinMode(compuerta, INPUT);
  pinMode(compuerta1, OUTPUT);
  pinMode(speak,OUTPUT);

  digitalWrite(compuerta1, HIGH); // inicio mi compuerta con un valor de 5v
}

void notificacion(){//aca esta la funcion de la notificacion de que se activo la alarma
  for(int x = 0; x < 2; x++){
  digitalWrite(Led, HIGH);
  digitalWrite(Led1, HIGH);
  tone(speak, 400,1); //generar tono de 400Hz durante 2 ms
  tone(speak, 2000);
  delay(150);
  digitalWrite(Led, LOW);
  digitalWrite(Led1, LOW);
  tone(speak, 400,1);
  tone(speak, 2000);
  delay(150);
  noTone(speak);
  }
}

void notificacion2(){//aca esta la funcion de la notificacion de que se activo la alarma
  for(int x = 0; x < 2; x++){
  digitalWrite(Led, HIGH);
  digitalWrite(Led1, HIGH);
  tone(speak, 2000,1); //generar tono de 400Hz durante 2 ms
  tone(speak, 400);
  delay(150);
  digitalWrite(Led, LOW);
  digitalWrite(Led1, LOW);
  tone(speak, 2000,1);
  tone(speak, 400);
  delay(150);
  noTone(speak);
  }
}

void activada(){ //aca la alarma se activa despues de ser llamada desde loop
  bool cont = false;
  bool estado = false;
  if(digitalRead(compuerta)==LOW){//comprueba si el estado de las puertas
    estado = true;
  }
  do{ //inicia un bucle comprobando el estado de las puertas.
  if(estado == true){
    alarma();
    }
   else{
    digitalWrite(Led, HIGH);
    delay(1000);
    digitalWrite(Led, LOW);
    delay(2000);
    if(digitalRead(pulsador)==HIGH){
    cont = true;
    break;}
    else {activada();}
    }
  if(digitalRead(pulsador)==HIGH){
    cont = true;
    break;
  }
  }while(cont == false);
  
}

void alarma(){//si las puertas estan abiertas o la alarma se activando dando una advertencia en sonido y lus.
  bool control = false;
  while(control == false){
  digitalWrite(Led1, HIGH);
  delay(250);
  digitalWrite(Led1, LOW);
  delay(250);
  for(int x=0; x<180; x++){ // iniciamos un pequeño ciclo que hace la variacion del tono
    //pasamos los grados a radianes
    sinval = (sin(x*(3.1412/180))); 
    //generamos el tono en frecuencia
    toneval = 2000+(int(sinval*1000));
    tone(speak, toneval);
    delay(2);
  }
  noTone(speak);
 if(digitalRead(pulsador)==HIGH)
  {
    control = true;
    noTone(speak);
    break;
    }
  }
}

void loop(){
  while(digitalRead(pulsador)==LOW);
  notificacion();
  activada();
  notificacion2();
  while(digitalRead(pulsador)==HIGH);
}
