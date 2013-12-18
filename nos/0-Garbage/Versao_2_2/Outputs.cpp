#include "Outputs.h"

Motor::Motor(int d1_PIN, int d2_PIN, int a_PIN)
{
	//Para a classe
	this->d1_PIN = d1_PIN;
	this->d2_PIN = d2_PIN;
	this->a_PIN = a_PIN;

	//inicializando os pinos
	pinMode(d1_PIN, OUTPUT);
	pinMode(d2_PIN, OUTPUT);
	pinMode(a_PIN, OUTPUT);
  	
  	//Dando um valor Inicial
          
	
	digitalWrite(a_PIN, LOW);
	digitalWrite(d1_PIN, LOW);
	digitalWrite(d2_PIN, LOW);
}

DirectionBox::DirectionBox(int a_PIN)
{
    myservo = new Servo();
	this->a_PIN = a_PIN;
    myservo->attach(a_PIN);
	int outputValue = map(0, SHRT_MIN, SHRT_MAX, 0, 180);  
    myservo->write(outputValue);
}

void Motor::frente(unsigned short int forca)
{
    Serial.print("poraa");

	digitalWrite(d1_PIN, LOW);
delay(10);
	digitalWrite(d2_PIN, LOW);
delay(10);
	digitalWrite(a_PIN, HIGH);
}

void Motor::re(unsigned short int forca)
{
        digitalWrite(a_PIN, LOW);
	digitalWrite(d1_PIN, LOW);
	digitalWrite(d2_PIN, LOW);
        delay(5);
      
	digitalWrite(a_PIN, LOW);
	digitalWrite(d1_PIN, HIGH);
        delay(5);
	digitalWrite(d2_PIN, HIGH);
}

void Motor::pare()
{
	digitalWrite(a_PIN, LOW);
	digitalWrite(d1_PIN, LOW);
	digitalWrite(d2_PIN, LOW);
}

void DirectionBox::esquerda(unsigned short int forca)
{
    myservo->write(forca);
}

void DirectionBox::centro()
{
    myservo->write(90);
}

void DirectionBox::direita(unsigned short int forca)
{
    myservo->write(forca);
}
