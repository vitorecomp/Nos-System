#ifndef IMASTER_H
#define IMASTER_H

#include "master.h"
#include "inode.h"
#include "iconnection.h"
#include "Defines.h"

class IMaster : protected Master{
private:
	void createNosList();
	void createConnectionList();
	void createSuperNosList();
};

#endif
