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
  	int outputValue = map(0, 0, 1023, 0, 255);  
  	analogWrite(a_PIN, outputValue);           
	

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
	analogWrite(a_PIN, 255); // this is the analog speed value for the arduino (0-255)
	digitalWrite(d1_PIN, HIGH);
	digitalWrite(d2_PIN, LOW); //turns the motors on - forwards
}

void Motor::re(unsigned short int forca)
{
	analogWrite(a_PIN, 255); // this is the analog speed value for the arduino (0-255)
	digitalWrite(d1_PIN, LOW);
	digitalWrite(d2_PIN, HIGH); //turns the motors on - forwards
}

void Motor::pare()
{
	analogWrite(a_PIN, 255); // this is the analog speed value for the arduino (0-255)
	digitalWrite(d1_PIN, LOW);
	digitalWrite(d2_PIN, LOW); //turns the motors on - forwards
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
