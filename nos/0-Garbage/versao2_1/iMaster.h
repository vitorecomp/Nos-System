#ifndef MASTER_H
#define MASTER_H

#include "master.h"
#include "inodes.h"
#include "iconnections.h"

class IMaster : public Master
{
private:
	void createNosList();
	void createConnectionList();
	void createSuperNosList();
};

#endif