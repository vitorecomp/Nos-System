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
    char *msgInr;
    msgInr = strtok(msg, "/;");
    if(!strcmp(msgInr, "motor"))
    {
    	msgInr = strtok(NULL, "/;");
    	int i = atoi(msgInr);
    	if(i == 0)
    		motor->pare();

    	if(i > 0)
    		motor->re(1);

    	if(i < 0)
    {  
        Serial.print("poraa");
    		motor->frente(1);
    }

    }
    Serial.println(msgInr);
    if(!strcmp(msgInr, "direcao"))
    {
    	msgInr = strtok(NULL, "/;");
    	int i = atoi(msgInr);
        Serial.println(msgInr);
        Serial.println(i);
    	if(i == 90)
    		direction->centro();

    	if(i > 90)
    		direction->direita(i - 20);

    	if(i < 90)
    		direction->esquerda(i + 20);

    }
}

CarAgent::CarAgent()
{

}

CarAgent::~CarAgent()
{

}

