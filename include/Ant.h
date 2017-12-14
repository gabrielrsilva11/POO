#ifndef ANT_H
#define ANT_H

#include "includeme.h"

class Ant{
 int ID;
 int energy;
 int PosX, PosY; //movimento coordenadas
 int Rvisao,Rmov; //raio de visão e de movimento
 char avatar;
 public:
     Ant();
     ~Ant();
};

class Cuidadora:public Ant{};
class Vigilante:public Ant{};
class Assaltante:public Ant{};
class Exploradora:public Ant{};
class FormigaGato:public Ant{}; //ultra formiga super poderosa

#endif // ANT_H
