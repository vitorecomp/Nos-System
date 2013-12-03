#ifndef NODE_H
#define NODE_H

#include <string.h>
#include <iostream>
#include <list>

using namespace std;

class NODE
{
private:
	string name;
	bool available;
public:

	string getName();
	bool isAvailable();

	virtual list<string> getServiceList() = 0;
	virtual void findNode() = 0;
	virtual void conectToNode(NODE*) = 0;
	virtual void executeService(string) = 0;
};

inline string NODE::getName()
{
	return this->name;
}

inline bool NODE::isAvailable()
{
	return this->available;
}

#endif