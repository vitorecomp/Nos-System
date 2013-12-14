#ifndef CONNECTIONS_H
#define CONNECTIONS_H

class Connection
{
	list<string> services;
public:
	virtual void initialize();
	virtual int connect();
	virtual int sendMessage(string);
	virtual list<Interrupts> reciveMessages();
	virtual bool verifyConnection();
	virtual list<string> getConnectionList();
};

#endif