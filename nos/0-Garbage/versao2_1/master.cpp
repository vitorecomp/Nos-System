#include "master.h"

void initialize()
{
	createNosList();
	createSuperNosList();
	createConnectionList();
	
	for(Lnode::interator n = nodes.begin(); n != nodes.end(); ++n)
	{
		nodesNames.push_back(n->getName());
	}
	for(Lsnode::interator n = sNodes.begin(); n != sNodes.end(); ++n)
	{
		sNodesNames.push_back(n->getName());
	}
}


void Master::run()
{
	while(1)
	{
		if(!interruptions.empty())
			executeInterruptionList();

		executeNos();
		executeConections();
		executeSuperNos();
	}

}

void Master::executeInterruptionList()
{
	int i = 0;
	for(Linterrupt::interator n = interruptions.begin(); n != interruptions.end(); ++n)
	{
		//pegando o nome do servico
		string serviceTemp = n->getService();
		char *service = new char [serviceTemp.length()+1];
  		strcpy (service, serviceTemp.c_str());
		char *name = strtok(service, "/");
		string serviceName(name, strlen(name)+1);
		if(inNodeList(serviceName))
		{
			for(Lnode::interator n = nodes.begin(); n != nodes.end(); ++n)
			{
				if(n->getName().compare(serviceTemp))
				{
					n->runService(serviceTemp);
				}
			}
			Node *temp = n;
			interruptions.remove(n);
			detroy(temp);
			continue;
		}
		if(inSuperNodeList(serviceName))
		{
			for(Lsnode::interator n = sNodes.begin(); n != sNodes.end(); ++n)
			{
				if(n->getName().compare(serviceTemp))
					n->runService(serviceTemp);
			}
			Node *temp = n;
			interruptions.remove(n);
			detroy(temp);
			continue;
		}

		int temp = inConnectionList(serviceName);
		if(temp >= 0)
		{
			for(Lconection::interator n = connections.begin(); n != connections.end(); ++n)
			{	
				if(temp == i)
					n->sendMessage(serviceTemp);
				i++;
			}
			Node *temp = n;
			interruptions.remove(n);
			detroy(temp);
		}
	}
}

void Master::executeNos()
{
	for(Lnode::interator n = nodes.begin(); n != nodes.end(); ++n)
	{
		n->run();
		Linterrupt temp = n->getInterrupts();
		for(Linterrupt::interator n = temp.begin(); n != temp.end(); ++n)
			interruptions.push_back(n);
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