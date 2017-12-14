#ifndef classes_H
#define classes_H

#include "includeme.h"
/* -- Classes and structures -- */

class Ant{
 int ID;
 int energy;
 int PosX, PosY;
};

class Nest{
  int ID;
  int energy;
  vector <Ant*> ants;
  int PosX_n, PosY_n;
};

class Migalha{
  int ID;
  int energy;
  int PosX, PosY;
};

#endif
