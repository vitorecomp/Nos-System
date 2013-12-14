#include "iMaster.h"

Master *imaster;
void setup()
{
  Serial.begin(9600);
  imaster =(Master*) new IMaster();
};

void loop()
{

  imaster->run();
};
