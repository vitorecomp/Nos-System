/**  \file   iMaster.h
     \brief  Cabecalho da classe que implemento o master atraves da classe master,
     essa classe implementa as caractericas do sistema, essas sao as instaciaçoes
     dos nos e das conexoes.*/
#ifndef IMASTER_H
#define IMASTER_H

#include "master.h"
#include "inode.h"
#include "iconnection.h"
#include "Defines.h"

#ifdef ARDUINO
     #include <Arduino.h>
#endif


/**  \class IMaster
     \brief Esse classe que implementa as estruturas basicas do sistema atraves do
     da classe base Master. Essa garante as instaciaçoes necessarias com os argumentos
     para cada no.
*/
class IMaster : public Master
{
private:
	/**  /fn void createNosList()
          /brief Funcao implementada para prover a instaciaçao da classe Master
          que e uma funçao instancia os sequintes nos implementados atraves 
          da classe Node.\n
               ->TemperatureNode   \n
               ->PinNode           \n
               ->MotorNode         \n
               ->DirectionBox      \n
               ->LightMode         \n*/
	void createNosList();

	/** \fn void createConnectionList()
          \brief Funcao que implementa a instaciação de conexoes do sistema,
          essa garante a correta inicialização das classes do sistema.*/
	void createConnectionList();

	/** \fn void createSuperNosList()
          \brief Funcao que 
     */
	void createSuperNosList();
public:

	/** \fn virtual void validate(const string& value) throw (invalid_argument) = 0
     *  \brief Validar os argumentos antes que estes sejam setados nas classes.
     *  \param value : e o valor a ser validado
     *  \exception std::invalid_argument o argumeto e invalido
     */
	IMaster();
};

#endif
