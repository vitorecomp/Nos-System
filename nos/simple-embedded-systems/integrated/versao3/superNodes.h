#ifndef SUPERNODES_H
#define SUPERNODES_H

#include "node.h"
#include <string.h>

/** \class BasicType
 *  \brief Essa e a classe responsavel por ser um padrao de classe para clases tipos basicos       \n
 *      tendo os metodos obrigratorios para todas essas e os mentodos mais gerais ja implemtados\n
 *      inline garantindo uma economia de memoria.
 */
class SuperNode
{
private:
	Node *nodes[100];				/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	StringList* dependenceNodes;	/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	StringList* myServices;			/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	StringList* interruptions;		/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
	char* name;						/**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/

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
	virtual void setNodeDependencesName() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual void setServiceList() = 0;

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void cleanInterrupts();


public:

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	StringList getDependecesNames();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void setNodeDependences(Node**);

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
	StringList* getServices();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	StringList* getInterrupts();


	/** \fn	 virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual int run() = 0;

	/** \fn	 virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	virtual int runService(char*) = 0;
};

#endif