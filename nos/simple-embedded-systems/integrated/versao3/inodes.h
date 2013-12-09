#ifndef INODES_H
#define INODES_H

#include "node.h"

class MotorNode : Node{
private:
	void setName();
	void setServiceList();
public:
	void run();
	void runService(char*);
};

class DirectionNode : Node
{
private:
	void setName();
	void setServiceList();
public:
	void run();
	void runService(char*);
};

class TemperatureNode : Node
{
private:
	void setName();
	void setServiceList();
public:
	void run();
	void runService(char*);
};

#endif
