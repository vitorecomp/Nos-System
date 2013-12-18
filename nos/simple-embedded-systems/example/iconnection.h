/**  \file   iconnection.h
     \brief  Cabecalho da classe que implemento as conexoes do sistema garantida que essa
     sejam inicializadas de forma corretado, provendo todos os paramentros. e tambem garantindo
     que usa dessa cominicaçao seja tranparente a outros modulos do sistema.*/
#ifndef ICONNECTION_H
#define ICONNECTION_H

#include "connection.h"
#include "Defines.h"

#ifdef ARDUINO
	#include <Arduino.h>
#endif

#ifdef LINUX
     #include <stdio.h>
#endif

/** \class BlueToothConnection
	\brief classe que implemento as conexao bluetooth do sistema garantida que essa
     sejam inicializadas de forma corretado, provendo todos os paramentros. e tambem garantindo
     que usa dessa cominicaçao seja tranparente a outros modulos do sistema.
*/
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
	#ifdef ARDUINO
	Serial.begin(9600);
	#endif
}

inline StringList* BlueToothConnection::reciveMessages()
{
	StringList *list = new StringList();
	#ifdef ARDUINO

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
	#endif

	#ifdef LINUX
	int count, i;
	char c = 0;
	char *msg = (char*)calloc(sizeof(char), 40);
	while(i < 40 && (c != END_MESSAGE) || c != '\n'){
		i++;
		cin >> c;
		if(c == '#')
			exit(0);
	}
	msg[i] = '\0';
	cout << "BlueToothConnection read : "<< msg << endl;
	return list;
	
	#endif
	
}

#endif