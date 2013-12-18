#include "iMaster.h"

void IMaster::createNosList()
{
	nodes[0] = (Node*) new MotorNode(RE_OUT_MOTOR_PIN, FRONT_T_OUT_MOTOR_PIN, FRONT_V_OUT_MOTOR_PIN);
	nodes[1] = (Node*) new DirectionNode(FRONT_OUT_LIGHT_PIN);
	nodes[2] = (Node*) new LigthNode();
}

void IMaster::createConnectionList()
{
	connections[0] = (Connection*)new BlueToothConnection()	;
}

void IMaster::createSuperNosList()
{
	
}

IMaster::IMaster()
{
	initialize();
}
