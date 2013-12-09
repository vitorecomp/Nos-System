#include "iMaster.h"

void IMaster::createNosList()
{
	nodes[0] = (Node*) new MotorNode(D1_OUT_MOTOR_PIN, D2_OUT_MOTOR_PIN, A1_OUT_MOTOR_PIN);
	nodes[1] = (Node*) new DirectionNode();
	nodes[2] = (Node*) new TemperatureNode();
}

void IMaster::createConnectionList()
{
	connections[0] = (Connection*)new BlueToothConnection()	;
}

void IMaster::createSuperNosList()
{
	
}
