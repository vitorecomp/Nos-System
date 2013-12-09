#ifndef INODES_H
#define INODES_H

#include "node.h"

class MotorNode : Node{
private:
	void setName();
	void setServiceList();
public:
	int run();
	int runService(string);
};

class DirectionNode : Node
{
private:
	void setName();
	void setServiceList();
public:
	int run();
	int runService(string);
};

class DirectionNode : Node
{
private:
	void setName();
	void setServiceList();
public:
	int run();
	int runService(string);
};

#endif
