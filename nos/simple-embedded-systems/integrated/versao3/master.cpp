#include "master.h"

void Master::initialize()
{
	interrupts = new StringList();
	for(int i = 0; i < 100; i ++)
	{
		nodes[i] = NULL;
		sNodes[i] = NULL;
		connections[i] = NULL;

		nodesNames[i]  = NULL;
		sNodesNames[i] = NULL;
	}

	createNosList();
	createSuperNosList();
	createConnectionList();
	
	for(int i = 0; nodes[i] != NULL; i++)
	{
		nodesNames[i] = nodes[i]->getName();
	}
	for(int i = 0; i < 100; i++)
	{
		sNodesNames[i] = sNodes[i]->getName();
	}
	Serial.println("/////loop");
}


void Master::run()
{

	Serial.println("loop");
	if(!interrupts->empty())
		executeInterruptionList();
	
	executeNos();
	executeConections();
	executeSuperNos();
}

void Master::executeInterruptionList()
{
	Serial.println("connection");
	if(!interrupts->empty()){
		Serial.println(interrupts->getFirst());
		while(1);
	}
	int nService = -1;
	StringList *nAtenInterrupts = new StringList();
	while(!interrupts->empty())
	{
		//pegando o nome do servico
		char service[100];
		char serviceTemp[100];
		char *serviceTemp2 = interrupts->pop();
		strcpy(serviceTemp, serviceTemp2);
		free(serviceTemp);
		strcpy(service, serviceTemp);
		char *serviceName = strtok(service, "/");

		//decobrindo onde sera executado
		int nService = inNodeList(serviceName);
		if(nService >= 0)
		{
			//executando servico
			nodes[nService]->runService(serviceTemp);
			continue;
		}
		nService = inSuperNodeList(serviceName);
		if(nService >= 0)
		{
			//executando o servico
			sNodes[nService]->runService(serviceTemp);
			continue;
		}

		nService = inConnectionList(serviceName);
		if(nService >= 0)
		{
			//executando o servico
			connections[nService]->sendMessage(serviceTemp);
			continue;
		}
		nAtenInterrupts->push(serviceTemp);
	}
	delete(interrupts);
	interrupts = nAtenInterrupts;
}

void Master::executeNos()
{
	for(int i = 0; nodes[i] != NULL; i++)
	{
		nodes[i]->run();
		Serial.println(nodes[i]->getName());
		interrupts->list_push_back(nodes[i]->getInterrupts());
	}
}

void Master::executeSuperNos()
{
	for(int i = 0; sNodes[i] != NULL; i++)
	{
		sNodes[i]->run();
		interrupts->list_push_back(sNodes[i]->getInterrupts());	
	}
}

void Master::executeConections()
{
	Serial.println("chegou aqui");
	for(int i = 0; connections[i] != NULL; i++)
	{
		interrupts->list_push_back(connections[i]->reciveMessages());	
	}
}

int Master::inNodeList(char *name)
{
	for(int i = 0; nodesNames[i] != NULL && i < 100; i++)
	{
		if(!strcmp(nodesNames[i], name))
			return i;
	}
	return -1;
}

int Master::inSuperNodeList(char *name)
{
for(int i = 0; nodesNames[i] !=NULL && i < 100; i++)
	{
		if(strcmp(sNodesNames[i],name))
			return i;
	}
	return -1;
}

int Master::inConnectionList(char *name){
	int i = 0;
	for(int i = 0; connections[i] != NULL; i++)
	{
		StringList *list = connections[i]->getConnectionList();
		for(int i = 0; !list->getN(i) == NULL; i++)
			if(strcmp(list->getN(i), name))
				return i;
	}
	return -1;
}