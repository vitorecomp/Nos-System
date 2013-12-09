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
	strcpy(services[0], "frente/X");
	strcpy(services[1], "tras/X");
	strcpy(services[2], "stop");
	
}

MotorNode::MotorNode(int d1_PIN, int d2_PIN, int a_PIN)
{
	initialize();
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
	interruptions = new StringList();
}

void MotorNode::runService(char *service)
{
	char *msgInr, *msg2;
    msgInr = strtok(service, "/;");
    msg2 = strtok(NULL, "/;");
	msgInr = strtok(NULL, "/;");
	int i = atoi(msgInr);
	if(!strcmp(msg2, "stop"))
		pare();

	if(!strcmp(msg2, "frente"))
		frente(i);

	if(!strcmp(msg2, "tras"))
		tras(i);
}

DirectionNode::DirectionNode(int a_PIN)
{
	initialize();
    myservo = new Servo();
	this->a_PIN = a_PIN;
    myservo->attach(a_PIN);
	int outputValue = map(0, SHRT_MIN, SHRT_MAX, 0, 180);  
    myservo->write(outputValue);
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
	strcpy(services[0], "left/X");
	strcpy(services[1], "rigth/X");
	strcpy(services[2], "center");
	
}

void DirectionNode::run(){
	interruptions = new StringList();
}

void DirectionNode::runService(char *service)
{
	char *msgInr, *msg2;
    msgInr = strtok(service, "/;");
    msg2 = strtok(NULL, "/;");
	msgInr = strtok(NULL, "/;");
	int i = atoi(msgInr);
	if(!strcmp(msg2, "center"))
		centro();

	if(!strcmp(msg2, "rigth"))
		direita(i + 70)	;

	if(!strcmp(msg2, "left"))
		esquerda(90 - i + 20);
}

void DirectionNode::esquerda(int forca)
{
    myservo->write(forca);
}

void DirectionNode::centro()
{
    myservo->write(90);
}

void DirectionNode::direita(int forca)
{
    myservo->write(forca);
}

TemperatureNode::TemperatureNode()
{
	initialize();
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

void TemperatureNode::run()
{
	interruptions = new StringList();	
}