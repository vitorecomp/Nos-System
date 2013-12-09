#ifndef ICONNECTION_H
#define ICONNECTION_H

class BlueToothConnection : Connection
{
public:
	void initialize();
	int connect();
	int sendMessage(string);
	StringLists reciveMessages();
	bool verifyConnection();
	StringLists getConnectionList();
};

#endif