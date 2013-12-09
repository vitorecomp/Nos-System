#ifndef CONNECTIONS_H
#define CONNECTIONS_H

class Connection
{
	list<string> services;
public:
	virtual void initialize() = 0;
	virtual int connect() = 0;
	virtual int sendMessage(string) = 0;
	virtual list<Interrupts> reciveMessages() = 0;
	virtual bool verifyConnection() = 0;
	virtual list<string> getConnectionList() = 0;
};

#endif