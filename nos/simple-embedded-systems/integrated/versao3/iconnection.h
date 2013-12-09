#ifndef ICONNECTION_H
#define ICONNECTION_H

#include "connection.h"
#include "Defines.h"
#include <Arduino.h>


class BlueToothConnection : Connection
{
public:
	BlueToothConnection();
	void initialize(){}
	int connect(){}
	int sendMessage(char *){}
	StringList* reciveMessages();
	bool verifyConnection(){}
	StringList* getConnectionList(){}
};

inline BlueToothConnection::BlueToothConnection()
{
	Serial.begin(9600);
}

inline StringList* BlueToothConnection::reciveMessages()
{
	StringList *list = new StringList();
	if (!Serial.available()){
		return list;
	}
	int i = 0;
	long long int p = 0;
	char c = 0;
	char *msg = (char*)malloc(sizeof(char)*40);
	while (c != END_MESSAGE && i < 40){
		p++;
		if (Serial.available()){
			c = Serial.read();
			msg[i] = c;
			i++;               
		}
		if(p >= 10000000)
		{
			Serial.println("Erro sem fim de msg");
			free(msg);
			return list;
		}
	}
	msg[i] = '\0';
	Serial.println(msg);
	list->push(msg);
	return list;
}

#endif