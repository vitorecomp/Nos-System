#ifndef SUPERNODES_H
#define SUPERNODES_H

#include "node.h"
#include <string.h>


class SuperNode
{
private:
	Node *nodes[100];
	StringList* dependenceNodes;
	StringList* myServices;
	StringList* interruptions;
	char* name;

	virtual void setName() = 0;
	virtual void setNodeDependencesName() = 0;
	virtual void setServiceList() = 0;
	void cleanInterrupts();


public:
	StringList getDependecesNames();
	void setNodeDependences(Node**);

	void initialize();
	char* getName();
	StringList* getServices();
	StringList* getInterrupts();

	virtual int run() = 0;
	virtual int runService(char*) = 0;
};

#endif