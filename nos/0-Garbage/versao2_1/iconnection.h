#ifndef ICONNECTION_H
#define ICONNECTION_H

class BlueToothConnection : Connection
{
public:
	void initialize();
	int connect();
	int sendMessage(string);
	list<Interrupts> reciveMessages();
	bool verifyConnection();
	list<string> getConnectionList();
};

#endif