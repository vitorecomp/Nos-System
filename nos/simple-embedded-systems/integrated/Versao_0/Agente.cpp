#include "Agente.h"


int Decoder::decode(char *msg, char **newMsg)
{
	*newMsg = msg;
	return 0;
}

void CarAgent::start()
{
	//
}

void CarAgent::reciveMessage(char* msg)
{
	this->msg = msg;
}

void CarAgent::execute()
{

	switch (msg[0])
	{
		case '0':
			motor->pare();
			break;
		case '1':
			motor->frente(30000);
			break;
		case '2':
			motor->re(30000);
              break;
        case '3':
            direction->esquerda(30000);
        	break;
        case '4':
        	direction->direita(30000);
        	break;
        case '5':
        	direction->centro();
        	break;


	}
msg[0] ='F';
}

CarAgent::CarAgent()
{

}

CarAgent::~CarAgent()
{

}

