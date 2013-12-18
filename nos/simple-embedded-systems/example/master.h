/**  \file   master.h
     \brief  Cabecalho das classes que prove o serviço do Master. Nesse esta contido todo o codigo necessario
     para se ter um Master implementado, faltando apenas os detalhes do sistema.
*/

#ifndef MASTER_H
#define MASTER_H

#include "node.h"
#include "connection.h"
#include "superNodes.h"

#ifdef LINUX
     #include <stdlib.h>
     #include <stdio.h>
#endif

#ifdef ARDUINO
	#include <Arduino.h>
#endif
#include <string.h>

/**  \class Master
     \brief Essa classe implementa a master esse e a parte principal do Nos-system ele e responsavel por
     controlar as todas as outras entidades do systema, como os nos, super nos conexoes e spys, ele
     tambem e resposavel por realizar a comunicação destes elementos entre si e com o mundo la fora
     atraves das connexoes.*/
class Master
{
protected:

	Node *nodes[100];				/**< Lista de nos instaciados pelo master*/
	SuperNode *sNodes[100];			/**< Lista de superNos instaciados pelo master*/
	Connection *connections[100];	/**< Lista de connecoes instaciadas pelo master*/

	char *nodesNames[100];			/**< Lista de nomes dos nos instaciados pelo master, gerada automaticamente*/
	char *sNodesNames[100];			/**< Lista de nomes dos super nos instaciados pelo master, gerada automaticamente*/

	StringList *interrupts;			/**< Lista de interrupçoes, variavel temporaria que armazena 
                                        as interrupções geradas pelos nos  ate que essa sejam atendidas*/
	
	/**  \fn int inNodeList(char* nodeName)
          \brief Verifica se um certo no esta dentro da lista de nos deste master.
          \param char* nodeName nome do no que se esta a procura.
          \return int que indica posiçao do no na lista de nos -1 se nao for localizado*/
	int inNodeList(char *);

	/** \fn int inSuperNodeList(char* superNodeName)
          \brief Verifica se um certo superno esta dentro da lista de supernos deste master.
          \param char* nodeName nome do superno que se esta a procura.
          \return int que indica posiçao do super no na lista de supernos, -1 se nao for localizado*/
	int inSuperNodeList(char *);

	/** \fn int inConnectionList(char* node)
          \brief Verifica se um certo no esta dentro da lista de nos / supernos das conecçoes lista de deste master.
          \param char* nodeName nome do no que se esta a procura.
          \return int que indica posiçao do conexao na lista de conexoes, -1 se nao for localizado*/
	int inConnectionList(char *);


	//functions

	/** \fn void executeNos()
		\brief executa todos os nos instanciados pelo master, esse tambem pega as 
		interrupçoes geradas por esse e as concatena na  sua lista de interrupçoes.*/
	void executeNos();

	/** \fn void executeSuperNos()
		\brief executa todos os Supernos instanciados pelo master, esse tambem pega as 
		interrupçoes geradas por esse e as concatena na  sua lista de interrupçoes.*/
	void executeSuperNos();

	/** \fn void executeConections()
		\brief recebe menssagens de todas as connexoes ativas que fazem parte do no
		defindo cada menssagem recebida como um interrupçao e as concatena na sua 
		lista de interrupçoes.*/
	void executeConections();

	/** \fn void passSpys
		\brief Pega a lista de interrupçoes e repassa para os spy que as dejeam ouvir
		permitindo que esses definam reaçoes ou mofiquem essas.*/
	void passSpys();

	/** \fn void executeInterruptionList()
		\brief executa a lista de interrupçoes temporarias do nos as repnasando para
		os reponsaveis por resolvelas, ou transmitilas. validando ainda se as chamdas
		de serviços estao de acorco com aquilo que e propostro por que ira receber
		essa interrupçoa*/
	void executeInterruptionList();

	/** \fn virtual void createNosList()
		\brief Aqui o programador deve precher a lista de nos com ponterios para os
		o nos do systema ja implementados atraveis de classe nao abtradas que herdem
		de node.*/
	virtual void createNosList() = 0;

	/** \fn virtual void createSuperNosList()
		\brief Aqui o programador deve precher a lista de supernos com ponterios para
		os supernos do systema ja implementados atraveis de classe nao abtradas que herdem
		de supernode.*/
	virtual void createSuperNosList() = 0;

	/** \fn virtual void createConnectionList()
		\brief Aqui o programador deve precher a lista de connecçoes com ponterios para
		as conecçoes do systema ja implementados atraves de classe nao abtradas que herdem
		de Connection.*/
	virtual void createConnectionList() = 0;
public:

	/** \fn void initialize()
          \brief responsavel por inicializar o master, instanciando os nos supernos spys
          e connecoes, fazendo ainda o necessario para o funcionamento consiso deste, 
          garantindo que tudo esteja ok antes da execucao dos serviços pelo No.*/
	void initialize();

	/** \fn void run()
          \brief realiza as interraçoes basicas de todos os elementos do sistema. gariantido que
          todos esses sejam executados e garitindo a passagem de menssagens entre eles e com o
          mundo exterior.*/
	void run();
};
#endif
