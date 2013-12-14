/**  \file   superNodes.h
     \brief  Cabecalho das classes que prove o serviço de super no. Nesse esta contido todo o codigo necessario
     para se ter um conito de super no implementado fora apenas o serviços implementados por estes
*/

#ifndef NOS_H
#define NOS_H

#include <string.h>
#include "Entidades.h"
using namespace std;


/** \class Node
     \brief Classe que reprensenta os nos essa define a estrutura basica de um no, essa tras
     a implentaçõa basico de um No, com as fiuncianlidades basicas ja implentadas levando apenas
     a implentaçao do No apenas a preocupaçao com detalhes dos serviços providos por esse*/
class Node
{
protected:
	char *name;				/**< Nome do no*/
	char ** services;			/**< Lista de serviços providos pelo no*/
	StringList* interruptions;	/**< Lista de interrupçoes gerados pelo no apos uma interaço ou uma chamada de serviço.*/

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void setName() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void setServiceList() = 0;

public:
	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void initialize();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	char* getName();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	char** getServices();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	StringList* getInterrupts();


	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void run() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void runService(char*) = 0;
};


#endif
