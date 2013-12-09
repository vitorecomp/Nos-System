#ifndef ENTIDADES_H
#define ENTIDADES_H

struct lStrings
{
	string Valor;
	LStrings *next;
} typedef LStrings;

class StringList
{
private:
	LStrings *list;
public:
	StringList();
	void list_push_back(StringList*);
	string pop();
	string getFirst();
	void push(string);
	bool empty();
};

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
	for(LStrings *termo = list; termo->next != NULL; termo = termo->next);
	termo->next = stringList->list;
}



string StringList::pop();
{
	string termo = new string();
	if(list == NULL)
		return termo;

	termo = list->Valor;
	lStrings *inter = list;
	list= list->next;
	destroy(list);
	return termo;
}

string StringList::getFirst();
{
	string termo = new string();
	if(list == NULL)
		return termo;

	termo = list->Valor;
	return termo;
}


#endif
