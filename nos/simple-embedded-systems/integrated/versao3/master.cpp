#include "master.h"

void initialize()
{
	for(int i = 0; i < 100; i ++)
	{
		nodes[i] = NULL;
		sNodes[i] = NULL;
		connections[i] = NULL;

		nodesNames[i].clear();
		sNodesNames[i].clear();
		interrupts[i].clear();
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
	while(1)
	{
		if(nInterruptions > 0)
			executeInterruptionList();

		executeNos();
		executeConections();
		executeSuperNos();
	}

}

void Master::executeInterruptionList()
{
	int nService = -1;
	for(int i = 0; nInterruptions > 0 || i < 100 ; i++)
	{
		if(interruptions[i].empty())
			continue;

		//pegando o nome do servico
		string serviceTemp = interruptions[i];
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
			//dizendo que o servico ja foi executado
			nInterruptions--;
			interruptions[i].clear();
			continue;
		}
		nService = inSuperNodeList(serviceName);
		if(nService >= 0)
		{
			//executando o servico
			sNodes[nService]->runService(serviceTemp);

			//dizendo que o servico ja foi executado
			nInterruptions--;
			interruptions[i].clear();
			continue;
		}

		nService = inConnectionList(serviceName);
		if(nService >= 0)
		{
			connections[nService]->sendMessage(serviceTemp);
				
			nInterruptions--;
			interruptions[i].clear();
		}
	}
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
	for(Lsnode::interator n = sNodes.begin(); n != sNodes.end(); ++n)
	{
		n->run();
		Linterrupt temp = n->getInterrupts();
		for(Linterrupt::interator n = temp.begin(); n != temp.end(); ++n)
			interruptions.push_back(n);	
	}
}

void Master::executeConections()
{
	for(Lconection::interator n = connections.begin(); n != connections.end(); ++n)
	{
		Linterrupt temp = n->reciveMessages();
		for(Linterrupt::interator n = temp.begin(); n != temp.end(); ++n)
			interruptions.push_back(n);
	}
}

bool Master::inNodeList(string name)
{
	for(Lstring::interator n = nodesNames.begin(); n != nodesNames.end(); ++n)
		if(n->getName.compare(name))
			return true;
	return false;
}

bool Master::inSuperNodeList(string name)
{
	for(Lstring::interator n = sNodesNames.begin(); n != sNodesNames.end(); ++n)
		if(n->getName.compare(name))
			return true;
	return false;
}	

int Master::inConnectionList(string name)
{
	int i = 0;
	for(Lstring::interator n = sNodesNames.begin(); n != sNodesNames.end(); ++n)
	{
		list<string> list = n->getConnectionList();
		for(Lstring::interator n2 = sNodesNames.begin(); n2 != sNodesNames.end(); ++n2)
			if(n2->getName.compare(name))
				return i;
		i++;
	}
	return -1;
}