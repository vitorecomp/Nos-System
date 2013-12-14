#ifndef SUPERNODES_H
#define SUPERNODES_H

#include "node.h"
#include <string.h>

/** \class SuperNode
 *  \brief Essa classe representa um superNo que implementa serviçosq que dependem de mais de um no, 
 *  esse coiceito permite que a comicaçao quase direta entre esse nos e tambem diminui varios problemas
 *  desse tipo de serviço pois agora ele so podera ser feito se os dois nos existirem. Evitando assim com
 *  que o serviço seja disponibilizado mesmo com uma de sua dependencias off.
 */
class SuperNode
{
private:
	Node *nodes[100];			/**< Nos que esse master controla.*/
	StringList* dependenceNodes;	/**< Nomes dos nos necessarios para instaciação do master.*/
	StringList* myServices;		/**< Lista de serviços que esse disponibilizada pelo superNo.*/
	StringList* interruptions;	/**< Lista de interrupçoes geradas pelo super no apos uma execução.*/
	char* name;				/**< Nome do superNo.*/

	/** \fn virtual void setName() = 0
     *  \brief Essa atruibui valor a variavel name, o seu respectivo valor. E uma função garante
     *  para na implementaçao dessa classe o programado set um nome para o super no garantindo
     *  assim o funcionamento cosiso do sistema. 
     */
	virtual void setName() = 0;

	/** \fn virtual void setNodeDependencesName()
     *  \brief Essa atribui a valor a lista que guarda o nome dos nos necessarios 
     *  para a instaciação dessa classe.E uma função garante que durante a
     *  implementaçao dessa classe o programado set essa lista para o superNo garantindo
     *  assim o funcionamento cosiso do sistema. 
     */
	virtual void setNodeDependencesName() = 0;

	/** \fn virtual void setServiceList() = 0
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