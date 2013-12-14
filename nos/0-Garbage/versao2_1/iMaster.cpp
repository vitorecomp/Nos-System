#include "iMaster.h"

void IMaster::createNosList()
{
	nodes.push((Node*) new MotorNode());
	nodes.push((Node*) new DirectionNode());
	nodes.push((Node*) new TemperatureNode());
}

void IMaster::createConnectionList()
{
	connections.push((Connection*)new BlueToothConnection());
}

void IMaster::createSuperNosList()
{
	
}
