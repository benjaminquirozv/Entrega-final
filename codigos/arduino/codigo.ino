// Puertos Arduino
#include <SoftwareSerial.h>
SoftwareSerial serialBT(3, 2); //se eligen los pines respectivos al módulo bluetooth

char state;

// se le añade un pin a cada rueda y arma
int ruedas_izquierda_adelante = 11;
int ruedas_izquierda_atras = 12;
int ruedas_derecha_adelante = 8;
int ruedas_derecha_atras = 10;
int arma = 4;

// Inicialización de variables
void setup()
{
  // todos los pines parten apagados
  pinMode(ruedas_izquierda_adelante, OUTPUT);
  pinMode(ruedas_izquierda_atras, OUTPUT);
  pinMode(ruedas_derecha_adelante, OUTPUT);
  pinMode(ruedas_derecha_atras, OUTPUT);
  pinMode(arma, OUTPUT);
  limpiarRuedas();   // todos los motores parten apagados
  limpiarArma(); //arma apagada
  Serial.begin(9600);
  serialBT.begin(9600);
}

void loop() {
  leerSerial();
}

// función que deja las ruedas apagas
void limpiarRuedas(){
  digitalWrite(ruedas_izquierda_adelante, 0);
  digitalWrite(ruedas_izquierda_atras, 0);
  digitalWrite(ruedas_derecha_adelante, 0);
  digitalWrite(ruedas_derecha_atras, 0);
}

// función que deja el arma apagada
void limpiarArma(){
  digitalWrite(arma, 0);
  }

// robot avanza
void avanza(){
  digitalWrite(ruedas_derecha_adelante, 1);
  digitalWrite(ruedas_izquierda_adelante, 1);
}

// robot retrocede
void retrocede(){
  digitalWrite(ruedas_derecha_atras, 1);
  digitalWrite(ruedas_izquierda_atras, 1);
}

// robot gira a la izquierda
void izquierda(){
  digitalWrite(ruedas_izquierda_atras, 1);
  digitalWrite(ruedas_derecha_adelante, 1);
}

// robot gira a la derecha
void derecha(){
  digitalWrite(ruedas_izquierda_adelante, 1);
  digitalWrite(ruedas_derecha_atras, 1);
}

// aquí se añaden instrucciones al serial, de manera que printee una letra en el código de arduino y con ello, puede ser interpretado en la app del celular
void leerSerial() {
  serialBT.listen(); 
  if (serialBT.available() > 0) {
    state = serialBT.read();
    Serial.println(state);
    
    if (state == 'G') {
      limpiarRuedas();
      avanza();
	}
    
    if (state == 'B') {
      limpiarRuedas();
      retrocede();
	}
    
    if (state == 'S') {
      limpiarRuedas();

	} 
    
    if (state == 'L') {
      limpiarRuedas();
      izquierda();
    }
    
    if (state == 'R') {
      limpiarRuedas();
      derecha();
    }
    
    if (state == 'W') {
      digitalWrite(arma,1);
      
    }
    if (state == 'M'){
      limpiarArma();
    }
    
    
  }
}


  
