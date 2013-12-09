#ifndef NOS_H
#define NOS_H

#include <string.h>
#include "Entidades.h"
using namespace std;


class Node
{
private:
	char *name;
	StringList* services;
	StringList* interruptions;

	virtual void setName() = 0;
	virtual void setServiceList() = 0;

public:
	void initialize();
	char* getName();
	StringList* getServices();
	StringList* getInterrupts();


	virtual void run() = 0;
	virtual void runService(char*) = 0;
};


#endif
