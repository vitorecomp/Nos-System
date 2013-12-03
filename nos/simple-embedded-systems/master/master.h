#ifndef MASTER_H
#define MASTER_H

using namespace std;

class Master
{
private:
	//list of nodes
	list<Node> nodes;
	//list of nodes names
	list<string> nodesNames;	
	//list of interruptions
	list<Interrupt> Interrupts;
	
	//functions
	void executeNos();
	void executeSuperNos();
	void executeConections();
	void passSpys();
	void executeInterruptionList();
	virtual void createNosList();
	virtual void createConnectionList();
public:
	Master();
	void run();
};
#endif