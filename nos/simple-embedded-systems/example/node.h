/**  \file   node.h
     \brief  Cabecalho das classes que prove o serviço de no. Nesse esta contido todo o codigo necessario
     para se ter um no implementado ,fora apenas o serviços implementados por estes.*/

#ifndef NOS_H
#define NOS_H

#include <string.h>
#include "Entidades.h"
using namespace std;


/**  \class Node
     \brief Classe que reprensenta os nos essa define a estrutura basica de um no, essa tras
     a implentaçõa basico de um No, com as fiuncianlidades basicas ja implentadas levando apenas
     a implentaçao do No apenas a preocupaçao com detalhes dos serviços providos por esse.*/
class Node
{
protected:
	char *name;				/**< Nome do no*/
	char ** services;			/**< Lista de serviços providos pelo no*/
	StringList* interruptions;	/**< Lista de interrupçoes gerados pelo no apos uma interaço ou uma chamada de serviço.*/

	/**  \fn virtual void setName()
          \brief Essa atruibui valor a variavel name, o seu respectivo valor. E uma função garante
          para na implementaçao dessa classe o programado set um nome para o no garantindo
          assim o funcionamento consiso do sistema. */
	virtual void setName() = 0;

     /**  \fn virtual void setServiceList()
          \brief Esse atribui valor lista de serviços que sao disponibilizados pelo no. E uma
          função garante que durante a implementaçao dessa classe o programdor set essa lista
          para o No garantindo assim o funcionamento consiso do sistema.*/
	virtual void setServiceList() = 0;

public:
	/** \fn void initialize()
          \brief responsavel por inicializar o No, garantindo que tudo esteja ok antes da
          execucao dos serviços pelo No.*/
	void initialize();

	/** \fn char* getName();
          \brief reporna o nome do No, podendo assim direcionar os serviços detinados a ele
          de forma correta.
          \return retorna o nome do No.*/
	char* getName();

	/** \fn StringList* getServices()
          \brief Retorna a lista de serviços disponibilizados pelo No, tornado assim
          possivel que o master consulte esse antes de enviar um requisiçao de serviço
          que nao seja implementado por esse no
          \return Lista de serviços implementados por esse No.*/
	char** getServices();

	/** \fn StringList* getInterrupts()
          \brief Retorna a lista de interrupçoes gerando pelo no apos a execução 
          de um serviço ou de um interação.
          /return A lista de interrupções geradas pelo No.*/
	StringList* getInterrupts();


	/** \fn virtual void run()
          \brief realiza as interraçoes basicas do no para cada interçao do master. Aqui se executa
          de forma continua as acoes ja que e chamado a cada interaçao do master, aqui tambem
           se gera a lista de interrupçoes se necessario, fazendo um processamento nao blocante.*/
	virtual void run() = 0;

	/** \fn virtual void run()
          \brief realiza as interraçoes basicas de um node para que cada interaçao deste feitas
          no metodo run() se comperte de acordo com o estado atual desse no, que foi criado pelo
          serviço. Aqui tambem pode-se gerar a listas de interrupçoes para o master.*/
	virtual void runService(char*) = 0;
};


#endif
