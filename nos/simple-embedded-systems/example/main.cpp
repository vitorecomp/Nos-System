#include "iMaster.h"
#include "master.h"
#ifdef LINUX
int main ()
{
	IMaster master;
	while(1)
		master.run();
}

#endif