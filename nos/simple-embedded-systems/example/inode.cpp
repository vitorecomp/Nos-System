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

MotorNode::MotorNode(int PIN1, int PIN2, int PIN3)
{
	initialize();

	//Para a classe
	this->BACK_PIN = PIN1;
	this->FRONT_T_PIN = PIN2;
	this->FRONT_V_PIN = PIN3;

	#ifdef ARDUINO
		//inicializando os pinos
		pinMode(PIN1, OUTPUT);
		pinMode(PIN2, OUTPUT);
		pinMode(PIN3, OUTPUT);
  	
		digitalWrite(PIN1, LOW);
		digitalWrite(PIN2, LOW);
		digitalWrite(PIN3, LOW);

	#endif

	#ifdef LINUX
		cout << "pino :" << PIN1 << " LOW" << endl;
		cout << "pino :" << PIN2 << " LOW" << endl;
		cout << "pino :" << PIN3 << " LOW" << endl;
	#endif
}

void MotorNode::frente(int forca)
{
	#ifdef ARDUINO
		digitalWrite(BACK_PIN, LOW);
		delay(5);
		digitalWrite(FRONT_T_PIN, HIGH);
		delay(5);
		digitalWrite(FRONT_V_PIN, HIGH);
		delay(5);
	#endif

	#ifdef LINUX
		cout << "pino :" << BACK_PIN << " LOW" << endl;
		cout << "delay : 5" << endl;
		cout << "pino :" << FRONT_T_PIN << " LOW" << endl;
		cout << "delay : 5" << endl;
		cout << "pino :" << FRONT_V_PIN << " LOW" << endl;
		cout << "delay : 5" << endl;
	#endif
}

void MotorNode::tras(int forca)
{
	#ifdef ARDUINO
		digitalWrite(FRONT_V_PIN, LOW);
		delay(5);
		digitalWrite(FRONT_T_PIN, LOW);
		delay(5);
		digitalWrite(BACK_PIN, HIGH);
		delay(5);
	#endif

	#ifdef LINUX
		cout << "pino :" << FRONT_V_PIN << " LOW" << endl;
		cout << "delay : 5" << endl;
		cout << "pino :" << FRONT_T_PIN << " LOW" << endl;
		cout << "delay : 5" << endl;
		cout << "pino :" << BACK_PIN << " HIGH" << endl;
		cout << "delay : 5" << endl;
	#endif
}

void MotorNode::pare()
{
	#ifdef ARDUINO
		digitalWrite(FRONT_V_PIN, LOW);
		delay(5);
		digitalWrite(BACK_PIN, LOW);
		delay(5);
		digitalWrite(FRONT_T_PIN, LOW);
		delay(5);
	#endif

	#ifdef LINUX
		cout << "pino :" << FRONT_V_PIN << " LOW" << endl;
		cout << "delay : 5" << endl;
		cout << "pino :" << BACK_PIN << " LOW" << endl;
		cout << "delay : 5" << endl;
		cout << "pino :" << FRONT_T_PIN << " LOW" << endl;
		cout << "delay : 5" << endl;
	#endif
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
	this->a_PIN = a_PIN;
	#ifdef ARDUINO
		myservo = new Servo();
    	myservo->attach(a_PIN);
		int outputValue = map(0, SHRT_MIN, SHRT_MAX, 0, 180);  
    	myservo->write(outputValue);
    #endif

    #ifdef LINUX
    	cout << "pino :" << a_PIN << " " << 90 << endl;
    #endif
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
	#ifdef ARDUINO
    	myservo->write(forca);
    #endif

    #ifdef LINUX
 		cout << "pino :" << a_PIN << " " << forca << endl;
 	#endif   	
}

void DirectionNode::centro()
{
	int forca = 90;
    #ifdef ARDUINO
    	myservo->write(forca);
    #endif

    #ifdef LINUX
 		cout << "pino :" << a_PIN << " " << forca << endl;
 	#endif   	
}

void DirectionNode::direita(int forca)
{
    #ifdef ARDUINO
    	myservo->write(forca);
    #endif

    #ifdef LINUX
 		cout << "pino :" << a_PIN << " " << forca << endl;
 	#endif  
}

LigthNode::LigthNode()
{
	initialize();
}


void LigthNode::setName()
{
	name = (char*)calloc(20, sizeof(char));
	strcpy(name, "light");
}

void LigthNode::setServiceList()
{
	services = (char**)malloc(sizeof(char*)*1);
	for(int i = 0; i < 1; i++)
		services[i] = (char*)calloc(20, sizeof(char));
	strcpy(services[0], "automatic");
}

void LigthNode::run()
{
	interruptions = new StringList();	
}