#ifndef NEST_H
#define NEST_H

#include "includeme.h"
#include "Ant.h"

class Nest{
  int ID;
  int energy;
  vector <Ant*> ants;
  int PosX_n, PosY_n;
  public:
      Nest();
      ~Nest();
};

#endif // NEST_H
