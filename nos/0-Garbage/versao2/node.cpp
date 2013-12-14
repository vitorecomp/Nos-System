#include "node.h"

void Node::initialize()
{
	setName();
	setServiceList();
}

string Node::getName()
{
	return name;
}

list<string> Node::getServices()
{
	return services;
}

list<Interruptions> Node::getInterrupts()
{
	list<Interruptions> temp
	while(!interruptions)
	{
		temp.push(interruptions.front());
		interruptions.pop;
	}
	return temp;
}