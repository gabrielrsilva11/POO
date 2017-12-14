#ifndef NEST_H
#define NEST_H

#include "includeme.h"
#include "Ant.h"

class Nest{
  int ID;
  int energy, nova, transfere;
  vector <Ant*> ants;
  int PosX_n, PosY_n;
  WORD corNinho;
  public:
      Nest();

     ~Nest();
     WORD getColor() const{return corNinho;}
};

#endif // NEST_H
