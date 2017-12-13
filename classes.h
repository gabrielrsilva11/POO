#ifndef classes_H
#define classes_H


/* -- Classes and structures -- */

class Ant{
 int ID;
 int energy;
 int PosX_a, PosY_a;
 //type of ant
};

class Nest{
  int ID;
  int energy;
  Ant *ants;
  int PosX_n, PosY_n;
};


#endif
