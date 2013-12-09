#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include "Entidades.h"

class Connection
{
	StringList services;
public:
	virtual void initialize() = 0;
	virtual int connect() = 0;
	virtual int sendMessage(char *) = 0;
	virtual StringList* reciveMessages() = 0;
	virtual bool verifyConnection() = 0;
	virtual StringList* getConnectionList() = 0;
};

#endif