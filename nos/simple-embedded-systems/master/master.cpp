#include "master.h"

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
		string serviceTemp = n.getService();
		char *service = new char [serviceTemp.length()+1];
  		strcpy (service, serviceTemp.c_str());
		strtok(service, "/");
		if(inNodeList())
		{
			for(Lnode::interator n = nodes.begin(); n != nodes.end(); ++n)
			{
				if(n.getName().compare(serviceTemp))
				{
					n.runService(serviceTemp);
				}
			}
			interruptions.remove(n);
			continue;
		}
		if(inSuperNodeList())
		{
			for(Lsnode::interator n = sNodes.begin(); n != sNodes.end(); ++n)
			{
				if(n.getName().compare(serviceTemp))
					n.runService(serviceTemp);
			}
			interruptions.remove(n);
			continue;
		}

		int temp = inConnectionList();
		if(temp >= 0)
		{
			for(Lconection::interator n = connections.begin(); n != connections.end(); ++n, i)
			{	
				if(temp == i)
					n.sendMessage(serviceTemp);
				i++;
			}
			interruptions.remove(n);
		}
	}
}

void Master::executeNos()
{
	for(Lnode::interator n = nodes.begin(); n != nodes.end(); ++n)
	{
		n.run();
		Linterrupt temp = n.getInterrupts();
		for(Linterrupt::interator n = temp.begin(); n != temp.end(); ++n)
			interruptions.push_back(n);
	}
}

void Mater::executeSuperNos();
{
	for(Lsnode::interator n = sNodes.begin(); n != sNodes.end(); ++n)
	{
		n.run();
		Linterrupt temp = n.getInterrupts();
		for(Linterrupt::interator n = temp.begin(); n != temp.end(); ++n)
			interruptions.push_back(n);	
	}
}

void Master::executeConections()
{
	for(Lconection::interator n = connections.begin(); n != connections.end(); ++n)
	{
		Linterrupt temp = n.reciveMessages();
		for(Linterrupt::interator n = temp.begin(); n != temp.end(); ++n)
			interruptions.push_back(n);
	}
}

