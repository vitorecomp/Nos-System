#ifndef MASTER_H
#define MASTER_H

#include "node.h"
#include "connection.h"
#include "superNodes.h"

#include <list>
#include <string.h>

using namespace std;

#define list<Node> Lnode;
#define list<SuperNode> Lsnode;
#define list<Connection> connections;
#define list<string> Lstring;
#define list<Interrupt> Linterrupt;

class Master
{
private:
	//list of nodes
	Lnode nodes;
	//list of supernodes
	Lsnode sNodes;
	//list of nodes names
	Lstring nodesNames;	
	Lstring sNodesNames;	
	//list of interruptions
	Linterrupt interrupts;
	

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