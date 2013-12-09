#include "iMaster.h"

IMaster *imaster;
void setup()
{
  imaster = new IMaster();
}

void loop()
{
  IMaster->run();
}
