#ifndef CONNECTIONS_H
#define CONNECTIONS_H

class Connection
{
	list<string> services;
public:
	virtual void initialize() = 0;
	virtual int connect() = 0;
	virtual int sendMessage(string) = 0;
	virtual StringLists reciveMessages() = 0;
	virtual bool verifyConnection() = 0;
	virtual StringLists getConnectionList() = 0;
};

#endif