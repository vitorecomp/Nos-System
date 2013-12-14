#include "Agente.h"
#include "Error.h"

#include "Defines.h"

//VARIAVEIS GLOBAIS
Agent *agentCar = NULL;
Decoder *agentDecoder = NULL;
Error *erro = NULL;
char msg[40];
int msgInterrupt = 0;
bool perdaSinal = false;

void setup()
{ 
       
	//Configurando as saidas
	Motor *motor = new Motor(D1_OUT_MOTOR_PIN, D2_OUT_MOTOR_PIN, A1_OUT_MOTOR_PIN);
	DirectionBox *directionBox = new DirectionBox(A1_OUT_DIRECTION_BOX_PIN);
        noInterrupts();
	//Configurando as entradas

	//Gerando o Agete Carrinho
 	CarAgent *car  = new CarAgent();
 	car->setMotor(motor);
 	car->setDirectionControl(directionBox);
 	
 	
 	agentCar = (Agent*) car;
 	agentDecoder = new Decoder();

 	//Gerando a AI;
 	//AI *android = new AI();

 	//Configurando erros
 	erro = new Error();

  	Serial.begin(9600);					//porta serial
 	//Habilitando as interrupçoes
 	interrupts();
}

//VARIAVEIS LOCAIS LOOP
int dest = 0;
char c = 0;
int i = 0;
char *newMsg = NULL;

void loop(){
	i = 0;
        c = 0;
	while(c != END_MESSAGE && i < 40)
	{
              if (Serial.available())
              {
		c = Serial.read();

		msg[i] = c;
                i++;               
              }
	}
        msg[i-1] = '\0'; 
	if (i > 40)
        	erro->messagemForaLimite(1);
	//decodifica a menssagem
	dest = agentDecoder->decode(msg, &newMsg);

	//passa a menssagem a diante
	switch (dest)
	{
		case 0:
			agentCar->reciveMessage(newMsg);
			agentCar->execute();                       
			//agentCar->addOnStack(actionStacks);
			break;
		case 2:
			//android->recieve(newMsg);
			//android->execute();
			//android->addOnStack(actionStacks);
			break;
	}
}



//INTERUPÇOES
void recieve()
{
	perdaSinal = false;
	msgInterrupt += 1;
	if(msgInterrupt > 10)
	{
		perdaSinal = true;
		return;
	}
}
