#ifndef MASTER_H
#define MASTER_H

#include "node.h"
#include "connection.h"
#include "superNodes.h"

#include <string.h>

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
	char *nodesNames[100];	
	char *sNodesNames[100];	
	//list of interruptions
	StringList *interrupts;
	

	int inNodeList(char *);
	int inSuperNodeList(char *);
	int inConnectionList(char *);


	//functions
	void executeNos();
	void executeSuperNos();
	void executeConections();
	void passSpys();
	void executeInterruptionList();
	virtual void createNosList() = 0;
	virtual void createSuperNosList() = 0;
	virtual void createConnectionList() = 0;
public:
	void initialize();
	void run();
};
#endif
