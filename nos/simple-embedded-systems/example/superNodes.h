/**  \file   superNodes.h
     \brief  Cabecalho das classes que prove o serviço de super no. Nesse esta contido todo o codigo necessario
     para se ter um conito de super no implementado fora apenas o serviços implementados por estes
*/

#ifndef SUPERNODES_H
#define SUPERNODES_H

#include "node.h"
#include <string.h>

/**  \class SuperNode
     \brief Essa classe representa um superNo que implementa serviços que dependem de mais de um no, 
     esse coiceito permite que a comicaçao quase direta entre esse nos e tambem diminui varios problemas
     desse tipo de serviço pois agora ele so podera ser feito se os dois nos existirem. Evitando assim com
     que o serviço seja disponibilizado mesmo com uma de sua dependencias off.*/
class SuperNode
{
protected:
	Node *nodes[100];			/**< Nos que esse master controla.*/
	StringList* dependenceNodes;	/**< Nomes dos nos necessarios para instaciação do master.*/
	StringList* myServices;		/**< Lista de serviços que esse disponibilizada pelo superNo.*/
	StringList* interruptions;	/**< Lista de interrupçoes geradas pelo super no apos uma execução.*/
	char* name;				/**< Nome do superNo.*/

	/**  \fn virtual void setName()
          \brief Essa atruibui valor a variavel name, o seu respectivo valor. E uma função garante
          para na implementaçao dessa classe o programado set um nome para o super no garantindo
          assim o funcionamento consiso do sistema.*/
	virtual void setName();

	/**  \fn virtual void setNodeDependencesName()
          \brief Essa atribui a valor a lista que guarda o nome dos nos necessarios 
          para a instaciação dessa classe.E uma função garante que durante a
          implementaçao dessa classe o programado set essa lista para o superNo garantindo
          assim o funcionamento cosiso do sistema.*/
	virtual void setNodeDependencesName();

	/**  \fn virtual void setServiceList()
          \brief Esse atribui valor lista de serviços que sao disponibilizados pelo super no.
          E uma função garante que durante a implementaçao dessa classe o programdor set essa
          lista para o superNo garantindo assim o funcionamento cosiso do sistema.*/
	virtual void setServiceList();

	/** \fn virtual void cleanInterrupts();
          \brief Responsavel por limpar as interrupçoes apos esse serem requisitadas pelos
          master, garantindo assim que essa nao sejas executadas novamente.*/
	void cleanInterrupts();


public:

	/**\fn  string getDependecesNames();
          \brief Essa retorna a lista e com os nomes dos nos nos necessarios para poder
          executar um servico immplentado, com essa se garante que o Master ao instaciar
          o super no ele passe os argumentos.
          \return Lista com os nomes dos nos depencias.*/
	StringList getDependecesNames();

	/**\fn void setNodeDependences(Node** nodeList)
          \brief Responsavel por dar um ser nos que seram usados durante a execuçao dos serviços
          e validar se todos os nos necessarios estao incluso no argumento passado a ela.
          \param  nodeList: a lista com os nodes que o super no depende para executar um serviço.*/
	void setNodeDependences(Node**);

	/** \fn void initialize();
          \brief responsavel por inicializar o super no, garantindo que tudo esteja ok antes da
          execucao dos serviços pelo super no.*/
	void initialize();

	/** \fn char* getName();
          \brief reporna o nome do superNo, podendo assim direcionar os serviços detinados a ele
          de forma correta.
          \return retorna o nome do superNo.*/
	char* getName();

	/** \fn StringList* getServices()
          \brief Retorna a lista de serviços disponibilizados pelo super No a partir do momento que
          todos os nos dos quais ele depende foram instacializado e devidamente setados. garantindo
          que o master nao chame sevicos nao implementados por esse super no.
          \retorn Lista de serviços implementados por esse super no.*/
	StringList* getServices();

	/** \fn StringList* getInterrupts()
          \brief Retorna a lista de interrupçoes gerando pelo super no apos a execução de um serviço
          ou de um interação.
          /retorn A lista de interrupções geradas pelo super no.*/
	StringList* getInterrupts();


	/** \fn virtual void run()
          \brief realiza as interraçoes basicas do super no para cada interçao do master. Aqui
          se exetuda de forma continua. neste se gera a lista de interrupçoes se necessario, e
          se faz um processamento nao blocante.*/
	virtual void run();

	/** \fn virtual void runService(char*)
          \brief relazida a interaçao basica apos a chamada de um serviço, executando o basico
          e preparando para que nas interraçoes run() o super no se comporte de maneira correta.
          aqui tambem podem ser geradas interrupçoes que devem ser add a lista de interrupçoes.*/
	virtual void runService(char*);
};

#endif