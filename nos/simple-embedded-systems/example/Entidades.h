/**  \file   Entidades.h
     \brief  Cabecalho da classe que implemento as entidades basicas do sistema
     garantindo com eles um melhor reaproveitamento do codigo, e tambem a melhor
     modularização e entedimento, essa ainda garantem uma validação basica de dados*/
#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "Defines.h"

#include <stdlib.h>
     
#ifdef ARDUINO
     #include <Arduino.h>
#endif

/**  \class lStrings
     \brief Estrutura que reprensanta um termo de uma lista de strings.*/
typedef struct lStrings
{
	char *Valor;
	struct lStrings *next;
}LStrings;

/**  \class StringList
     \brief Essa classe apresenta as funçoes basicas para trabalho em uma lista de strings.*/
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
