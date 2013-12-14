#ifndef ICONNECTION_H
#define ICONNECTION_H

#include "connection.h"
#include "Defines.h"
#include <Arduino.h>


class BlueToothConnection : Connection
{
public:
	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	BlueToothConnection();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void initialize(){}

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	int connect(){}

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	int sendMessage(char *){}

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	StringList* reciveMessages();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	bool verifyConnection(){}

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
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
	char *msg = (char*)calloc(sizeof(char), 40);
	while (c != END_MESSAGE && i < 40){
		if (Serial.available()){
			c = Serial.read();
			msg[i] = c;
			i++;               
		}
	}
	msg[i] = '\0';
	Serial.println(msg);
	list->push(msg);
	return list;
}

#endif