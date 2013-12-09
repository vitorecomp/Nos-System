#include "iMaster.h"

Master *imaster;
void setup()
{
  imaster =(Master*) new IMaster();
};

void loop()
{
  imaster->run();
};
