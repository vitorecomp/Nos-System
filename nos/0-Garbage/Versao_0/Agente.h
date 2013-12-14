#ifndef AGENTES_H
#define AGENTES_H

#include <string.h>
#include "Outputs.h"


class Agent
{
public:
	virtual void start() = 0;
	virtual void execute() = 0;
	virtual void reciveMessage(char*) = 0;
};


class CarAgent : public Agent
{
private:
	Motor *motor;
	DirectionBox *direction;
	char *msg;
	//OutPuts

public:
	void setMotor(Motor *);
	void setDirectionControl(DirectionBox *);
	void start();
	void execute();
	void reciveMessage(char*);
	CarAgent();
	~CarAgent();
};

inline void CarAgent::setMotor(Motor *motor){
	this->motor = motor;
};

inline void CarAgent::setDirectionControl(DirectionBox *direction){
	this->direction = direction;
};

class Decoder
{
public:
	int decode(char*, char**);
};


#endif
