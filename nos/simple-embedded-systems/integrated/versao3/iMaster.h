#ifndef IMASTER_H
#define IMASTER_H

#include "master.h"
#include "inode.h"
#include "iconnection.h"
#include "Defines.h"
#include <Arduino.h>

class IMaster : protected Master{
private:
	void createNosList();
	void createConnectionList();
	void createSuperNosList();
public:
	IMaster();
};

inline IMaster::IMaster()
{
	initialize();
}

#endif
