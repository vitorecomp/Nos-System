#ifndef SUPERNODES_H
#define SUPERNODES_H

#include "node.h"
#include <string.h>

using namespace std;

class SuperNodes
{
private:
	list<*Node> nodes;
	list<sting> dependenceNodes;
	list<string> myServices;
	list<Interrupts> interruptions;
	string myName;

	virtual void setName() = 0;
	virtual void setNodeDependencesName() = 0;
	virtual void setServiceList() = 0;
	void cleanInterrupts();


public:
	list<string> getDependecesNames();
	void setNodeDependences(list<*Node>);

	void initialize();
	string getName();
	list<string> getServices();
	list<Interrupts> getInterrupts();
	void returnInterruts(list<Interrupts>);


	virtual int run() = 0;
	virtual int runService(string) = 0;
};

#endif