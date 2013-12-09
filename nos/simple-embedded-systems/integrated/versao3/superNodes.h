#ifndef SUPERNODES_H
#define SUPERNODES_H

#include "node.h"
#include <string.h>

using namespace std;

class SuperNodes
{
private:
	Node *nodes[100];
	StringLists dependenceNodes;
	StringLists myServices;
	StringLists interruptions;
	string myName;

	virtual void setName() = 0;
	virtual void setNodeDependencesName() = 0;
	virtual void setServiceList() = 0;
	void cleanInterrupts();


public:
	StringLists getDependecesNames();
	void setNodeDependences(list<*Node>);

	void initialize();
	string getName();
	StringLists getServices();
	StringLists getInterrupts();

	virtual int run() = 0;
	virtual int runService(string) = 0;
};

#endif