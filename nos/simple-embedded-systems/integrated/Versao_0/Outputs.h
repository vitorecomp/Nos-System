#ifndef OUTPUTS_H
#define OUTPUTS_H

#include <stdlib.h>
#include <Arduino.h>
#include "Servo.h"
#include <limits.h>


class Output
{

};

class Motor: public Output
{
private:
	int d1_PIN;
	int d2_PIN;
	int a_PIN;
public:
	Motor(int, int , int);
	void frente(unsigned short int);
	void re(unsigned short int);
	void pare();
};

class DirectionBox : public Output
{
private:
    Servo *myservo;
	int a_PIN;
public:
	DirectionBox(int);
	void direita(unsigned short int);
	void esquerda(unsigned short int);
	void centro();
};

#endif

