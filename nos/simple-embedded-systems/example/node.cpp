#include "node.h"

void Node::initialize()
{
	interruptions = new StringList();
	setName();
	setServiceList();
}

char* Node::getName()
{
	return name;
}

char** Node::getServices()
{
	return services;
}

StringList* Node::getInterrupts()
{
	StringList* list = this->interruptions;
	interruptions= NULL;	
	return list;
}