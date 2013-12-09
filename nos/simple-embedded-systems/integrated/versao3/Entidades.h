#ifndef ENTIDADES_H
#define ENTIDADES_H

#include <stdlib.h>
#include <Arduino.h>

typedef struct lStrings
{
	char *Valor;
	struct lStrings *next;
}LStrings;

class StringList
{
private:
	LStrings *list;
public:
	StringList();
	void list_push_back(StringList*);
	char* pop();
	char* getFirst();
	void push(char*);
	bool empty();
	char* getN(int);
};

#endif
