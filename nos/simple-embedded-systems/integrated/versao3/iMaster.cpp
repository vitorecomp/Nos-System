#include "iMaster.h"

void IMaster::createNosList()
{
	nodes[0] = new MotorNode();
	nodes[1] = new DirectionNode();
	nodes[2] = new TemperatureNode();
}

void IMaster::createConnectionList()
{
	connections[0] = new BlueToothConnection()	;
}

void IMaster::createSuperNosList()
{
	
}
