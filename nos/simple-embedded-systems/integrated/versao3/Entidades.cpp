#include "Entidades.h"

StringList::StringList()
{
	list = NULL;
}


bool StringList::empty()
{
	if(list == NULL)
		return true;
	else
		return false;
}

void StringList::push(string)
{
	LStrings *termo= new lStrings;
	termo->next = list;
	list = termo;
}

void StringList::list_push_back(stringList)
{
	if(termo == NULL){
		list = stringList;
	}else{
		for(LStrings *termo = list; termo->next != NULL; termo = termo->next);
		termo->next = stringList->list;
	}
}



string StringList::pop();
{
	string termo = new string();
	if(list == NULL)
		return termo;

	termo = list->Valor;
	lStrings *inter = list;
	list= list->next;
	delete(list);
	return termo;
}

string StringList::getFirst();
{
	return getN(0);
}

string StringList::getN(int ni);
{
	string termo = new string();
	for(lStrings *iList = list, int i = 0; iList != NULL; iList = iList->next, i++)
		if(i == ni)
		{
			termo = iList->Valor;
			return termo;
		}
	return termo;
}

