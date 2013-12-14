#ifndef BASE_TYPE
#define BASE_TYPE

#include <string.h>

class Interrupt
{
private:
	string service;
public:
	Interrupt(string)
	void getService();
};

Interrupt::Interrupt(string service)
{
	this->service = service;
}

string Interrupt::getService()
{
	return this->service;
}


#endif