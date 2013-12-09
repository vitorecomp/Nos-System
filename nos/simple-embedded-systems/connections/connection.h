#ifndef CONNECTIONS_H
#define CONNECTIONS_H

class Connection
{
	list<string> services;
public:
	virtual void initialize();
	virtual int connect();
	virtual int sendMessage();
	virtual list<string> reciveMessages();
	virtual int verifyConnection();
};

#endif