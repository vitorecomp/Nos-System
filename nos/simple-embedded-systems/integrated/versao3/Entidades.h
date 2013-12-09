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
	string getN(int);
};

#endif
