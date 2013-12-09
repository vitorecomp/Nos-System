#include "superNodes.h"

void SuperNode::initialize()
{
	setName();
	setServiceList();
}

char* SuperNode::getName()
{
	return name;
}

StringList* SuperNode::getServices()
{
	return myServices;
}

StringList* SuperNode::getInterrupts()
{
	StringList* list = this->interruptions;
	interruptions= NULL;	
	return list;
}