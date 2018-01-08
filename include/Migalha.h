#ifndef MIGALHA_H
#define MIGALHA_H

#include "includeme.h"

class Migalha{
  static int counter;
  int ID;
  int energy;
  int energyAtual;
  int PosX, PosY;
  public:
      Migalha(int a, int b , int c):energy(a),PosX(b),PosY(c){
        ID = ++counter;
        energyAtual = energy;
      };
      void setEnergyAtual(int x){
        energyAtual += x;
      }
      bool checkDestroy(){
        if(energyAtual <= (energy * 0.1))
          return true;
        return false;
      }
      int getPosX() const{
        return PosX;
      }
      int getPosY() const{
        return PosY;
      }
      int getID() const{
        return ID;
      }
      int getEnergyAtual() const{
        return energyAtual;
      }
      int getInfo() const{
        ostringstream os;
        oss << "ID: " << getID() << " Energia Atual: " << getEnergyAtual() << " Posx: " << getPosX() << " PosY: " << getPosY() << endl;
      }
      virtual ~Migalha();
};


#endif // MIGALHA_H
