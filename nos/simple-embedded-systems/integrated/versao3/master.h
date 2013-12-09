#ifndef MASTER_H
#define MASTER_H

#include "node.h"
#include "connection.h"
#include "superNodes.h"

#include <Arduino.h>
#include <string.h>

/** \class BasicType
 *  \brief Essa e a classe responsavel por ser um padrao de classe para clases tipos basicos       \n
 *      tendo os metodos obrigratorios para todas essas e os mentodos mais gerais ja implemtados\n
 *      inline garantindo uma economia de memoria.
 */
class Master
{
protected:
	//list of nodes
	Node *nodes[100];				/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	//list of supernodes
	SuperNode *sNodes[100];			/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	//list of connection
	Connection *connections[100];	/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	//list of nodes names 			
	char *nodesNames[100];			/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	char *sNodesNames[100];			/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	//list of interruptions
	StringList *interrupts;			/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	
	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	int inNodeList(char *);

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	int inSuperNodeList(char *);

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	int inConnectionList(char *);


	//functions

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void executeNos();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void executeSuperNos();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void executeConections();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void passSpys();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void executeInterruptionList();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void createNosList() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void createSuperNosList() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void createConnectionList() = 0;
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
	void run();
};
#endif
