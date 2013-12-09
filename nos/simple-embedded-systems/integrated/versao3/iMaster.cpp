#include "iMaster.h"

void IMaster::createNosList()
{
	nodes[0] = (Node*)new MotorNode();
	nodes[1] = (Node*)new DirectionNode();
	nodes[2] = (Node*)new TemperatureNode();
}

void IMaster::createConnectionList()
{
	connections[0] = (Connection*)new BlueToothConnection()	;
}

void IMaster::createSuperNosList()
{
	
}
