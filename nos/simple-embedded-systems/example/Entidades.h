#ifndef ENTIDADES_H
#define ENTIDADES_H

#include <stdlib.h>
#include <Arduino.h>

/** \class BasicType
 *  \brief Essa e a classe responsavel por ser um padrao de classe para clases tipos basicos       \n
 *      tendo os metodos obrigratorios para todas essas e os mentodos mais gerais ja implemtados\n
 *      inline garantindo uma economia de memoria.
 */
typedef struct lStrings
{
	char *Valor;
	struct lStrings *next;
}LStrings;

/** \class BasicType
 *  \brief Essa e a classe responsavel por ser um padrao de classe para clases tipos basicos       \n
 *      tendo os metodos obrigratorios para todas essas e os mentodos mais gerais ja implemtados\n
 *      inline garantindo uma economia de memoria.
 */
class StringList
{
private:
	LStrings *list; /**< Esta string e usada para armazenar as informaçoes repassadas de cada classe apos a validaçao destas*/
public:
	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	StringList();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void list_push_back(StringList*);

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	char* pop();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	char* getFirst();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	void push(char*);

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	bool empty();

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	char* getN(int);
};

#endif
