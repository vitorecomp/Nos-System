#ifndef NOS_H
#define NOS_H

#include <string.h>

using namespace std;


class Node
{
private:
	string name;
	list<string> services;
	list<Interrupts> interruptions;

	virtual void setName() = 0;
	virtual void setServiceList() = 0;

public:
	void initialize();
	string getName();
	list<string> getServices();
	list<Interrupts> getInterrupts();


	virtual int run() = 0;
	virtual int runService(string) = 0;
};


#endif