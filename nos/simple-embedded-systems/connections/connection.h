/**  \file   connection.h
     \brief  Cabecalho da classe que implemento  a interface basica das conexoes do sistema 
     para que  o uso dessa cominicaçao seja tranparente a outros modulos do sistema e tambem
     permitindo ao programados modificaçoes grandes que normamentes sao necessarios para 
     o uso de uma connexão*/
#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include "Entidades.h"
#ifdef LINUX
     #include<stdio.h>
#endif

/**  \class Connection
     \brief lasse que implemento  a interface basica das conexoes do sistema 
     para que  o uso dessa cominicaçao seja tranparente a outros modulos do sistema e tambem
     permitindo ao programados modificaçoes grandes que normamentes sao necessarios para 
     o uso de uma connexão.*/
class Connection
{
	StringList services; /**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	
public:
	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void initialize() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual int connect() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual int sendMessage(char *) = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual StringList* reciveMessages() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual bool verifyConnection() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual StringList* getConnectionList() = 0;
};

#endif