#ifndef ICONNECTION_H
#define ICONNECTION_H

#include "connection.h"


class BlueToothConnection : Connection
{
public:
	void initialize(){}
	int connect(){}
	int sendMessage(char *){}
	StringList* reciveMessages(){}
	bool verifyConnection(){}
	StringList* getConnectionList(){}
};

#endif