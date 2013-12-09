#ifndef INODES_H
#define INODES_H

#include "node.h"

#include <stdlib.h>
#include <Arduino.h>
#include "Servo.h"
#include <limits.h>

class MotorNode : Node{
private:
	int d1_PIN;
	int d2_PIN;
	int a_PIN;

	void setName();
	void setServiceList();

	void frente(int);
	void tras(int);
	void pare();
public:
	MotorNode(int, int, int);
	void run();
	void runService(char*);
};

class DirectionNode : Node
{
private:

	void setName();
	void setServiceList();
public:
	void run(){}
	void runService(char*){}
};


class TemperatureNode : Node
{
private:
	void setName();
	void setServiceList();
public:
	void run(){}
	void runService(char*){}
};

#endif
