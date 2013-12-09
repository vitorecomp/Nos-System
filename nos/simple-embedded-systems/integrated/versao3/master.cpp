#include "master.h"

void initialize()
{
	interruptions = new StringList();
	for(int i = 0; i < 100; i ++)
	{
		nodes[i] = NULL;
		sNodes[i] = NULL;
		connections[i] = NULL;

		nodesNames[i].clear();
		sNodesNames[i].clear();
	}

	createNosList();
	createSuperNosList();
	createConnectionList();
	
	for(int i = 0; nodes[i] != NULL; i++)
	{
		nodesNames[i] = nodes[i].getName();
	}
	for(int i = 0; i < 100; i++)
	{
		sNodesNames[i] = sNodes[i].getName();
	}
}


void Master::run()
{
	if(!interruptions->empty())
		executeInterruptionList();

	executeNos();
	executeConections();
	executeSuperNos();
}

void Master::executeInterruptionList()
{
	int nService = -1;
	StringLists *nAtenInterrupts = new StringList();
	while(!interruptions->empty())
	{
		//pegando o nome do servico
		string serviceTemp = interruptions.pop();
		char *service = new char [serviceTemp.length()+1];
  		strcpy (service, serviceTemp.c_str());
		char *name = strtok(service, "/");
		string serviceName(name, strlen(name)+1);

		//decobrindo onde sera executado
		int nService = inNodeList(serviceName);
		if(nService >= 0)
		{
			//executando servico
			nodes[nService]->run(serviceTemp);
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
	delete(interruptions);
	interruptions = nAtenInterrupts;
}

void Master::executeNos()
{
	for(int i = 0; nodes[i] != NULL; i++)
	{
		nodes[i]->run();
		interruptions.list_push_back(node[i]->getInterrupts());
		
	}
}

void Mater::executeSuperNos();
{
	for(int i = 0; sNodes[i] != NULL; i++)
	{
		sNodes[i]->run();
		interruptions.list_push_back(sNode[i]->getInterrupts());	
	}
}

void Master::executeConections()
{
	for(int i = 0; connections[i] != NULL; i++)
	{
		interruptions.list_push_back(connections[i]->reciveMessages());	
	}
}

bool Master::inNodeList(string name)
{
	for(int i = 0; !nodesNames[i].empty() && i < 100; i++)
	{
		if(nodesNames[i].compare(name))
			return i;
	}
	return -1;
}

bool Master::inSuperNodeList(string name)
{
for(int i = 0; !NodesNames[i].empty() && i < 100; i++)
	{
		if(sNodesNames[i].compare(name))
			return i;
	}
	return -1;	

int Master::inConnectionList(string name)
{
	int i = 0;
	for(int i = 0; connections[i] != NULL; i++)
	{
		StringList *list = connections[i]->getConnectionList();
		for(int i = 0; !list->getN(i).empty(); i++)
			if(list->getN(i).compare(name))
				return i;
	}
	return -1;
}