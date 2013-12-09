#include "inode.h"

void MotorNode::setName()
{
	name = (char*)calloc(20, sizeof(char));
	strcpy(name, "motor");
}

void MotorNode::setServiceList()
{
	
	services = (char**)malloc(sizeof(char*)*3);
	for(int i = 0; i < 3; i++)
		services[i] = (char*)calloc(20, sizeof(char));
	strcpy(services[0], "frente/X/X");
	strcpy(services[1], "tras/X/X");
	strcpy(services[2], "stop/X");
	
}

MotorNode::MotorNode(int d1_PIN, int d2_PIN, int a_PIN)
{
	//Para a classe
	this->d1_PIN = d1_PIN;
	this->d2_PIN = d2_PIN;
	this->a_PIN = a_PIN;

	//inicializando os pinos
	pinMode(d1_PIN, OUTPUT);
	pinMode(d2_PIN, OUTPUT);
	pinMode(a_PIN, OUTPUT);
  	
  	//Dando um valor Inicial
  	int outputValue = map(0, 0, 1023, 0, 255);  
  	analogWrite(a_PIN, outputValue);           
	

	digitalWrite(d1_PIN, LOW);
	digitalWrite(d2_PIN, LOW);
}

void MotorNode::frente(int forca)
{
	analogWrite(a_PIN, forca); // this is the analog speed value for the arduino (0-255)
	digitalWrite(d1_PIN, HIGH);
	digitalWrite(d2_PIN, LOW); //turns the motors on - forwards
}

void MotorNode::tras(int forca)
{
	analogWrite(a_PIN, forca); // this is the analog speed value for the arduino (0-255)
	digitalWrite(d1_PIN, LOW);
	digitalWrite(d2_PIN, HIGH); //turns the motors on - forwards
}

void MotorNode::pare()
{
	analogWrite(a_PIN, 255); // this is the analog speed value for the arduino (0-255)
	digitalWrite(d1_PIN, LOW);
	digitalWrite(d2_PIN, LOW); //turns the motors on - forwards
}

void MotorNode::run()
{

}

void MotorNode::runService(char *service)
{

}

void DirectionNode::setName()
{
	name = (char*)calloc(20, sizeof(char));
	strcpy(name, "direction");
}

void DirectionNode::setServiceList()
{
	
	services = (char**)malloc(sizeof(char*)*3);
	for(int i = 0; i < 3; i++)
		services[i] = (char*)calloc(20, sizeof(char));
	strcpy(services[0], "left/X/X");
	strcpy(services[1], "rigth/X/X");
	strcpy(services[2], "center/X");
	
}

void TemperatureNode::setName()
{
	name = (char*)calloc(20, sizeof(char));
	strcpy(name, "temperature");
}

void TemperatureNode::setServiceList()
{
	services = (char**)malloc(sizeof(char*)*1);
	for(int i = 0; i < 1; i++)
		services[i] = (char*)calloc(20, sizeof(char));
	strcpy(services[0], "ambiente/X");
}
