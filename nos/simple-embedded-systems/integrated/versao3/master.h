#ifndef MASTER_H
#define MASTER_H

#include "node.h"
#include "connection.h"
#include "superNodes.h"

#include <string.h>

using namespace std;

class Master
{
private:
	//list of nodes
	Node *nodes[100];
	//list of supernodes
	SuperNodes *sNodes[100];
	//list of connection
	Connection *connections[100];
	//list of nodes names
	string nodesNames[100];	
	string sNodesNames[100];	
	//list of interruptions
	StringLists *interrupts;
	

	bool inNodeList();
	bool inSuperNodeList();
	int inConnectionList();


	//functions
	void executeNos();
	void executeSuperNos();
	void executeConections();
	void passSpys();
	void executeInterruptionList();
	virtual void createNosList();
	virtual void createSuperNosList();
	virtual void createConnectionList();
public:
	void initialize();
	void run();
};
#endif
