#ifndef IMASTER_H
#define IMASTER_H

#include "master.h"
#include "inodes.h"
#include "iconnection.h"

class IMaster : public Master{
private:
	void createNosList();
	void createConnectionList();
	void createSuperNosList();
};

#endif
