#ifndef MIGALHA_H
#define MIGALHA_H

#include "includeme.h"


class Migalha{
  static int counter;
  int ID;
  int energy;
  int energyAtual;
  Posicao posicao;
  public:
      Migalha(int a, int li , int col):energy(a),posicao(li,col){
        ID = ++counter;
        energyAtual = energy;
      }
      void setEnergyAtual(int x){
        energyAtual += x;
      }
      bool checkDestroy(){
        if(energyAtual <= (energy * 0.1))
          return true;
        return false;
      }
      int getLinha() const{
        return posicao.getLinha();
      }
      int getColuna() const{
        return posicao.getColuna();
      }
      int getID() const{
        return ID;
      }
      int getEnergyAtual() const{
        return energyAtual;
      }
      string getInfo() const{
        ostringstream os;
        os << "ID: " << getID() << " Energia Atual: " << getEnergyAtual() << " Linha: " << getLinha() << " Coluna: " << getColuna() << endl;
        return os.str();
      }
      virtual ~Migalha(){};
};


#endif // MIGALHA_H
