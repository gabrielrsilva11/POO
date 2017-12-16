#ifndef NEST_H
#define NEST_H

#include "includeme.h"
#include "Ant.h"

class Nest{
  static int counter;
  char avatar;
  int ID;
  int energy, nova, transfere;
  vector <Ant*> ants;
  int PosX_n, PosY_n;
  WORD corNinho;
  public:
      Nest(int a, int b, int c, int d, int e, WORD cor):energy(a),nova(b),transfere(c),PosX_n(d),PosY_n(e),corNinho(cor){
        ID = ++counter;
      };
      int getID() const{
        return ID;
      }
      int getEnergy() const{
        return energy;
      }
      int getNova() const{
        return nova;
      }
      int getTransfere() const{
        return transfere;
      }
      int getPosX() const{
        return PosX_n;
      }
      int getPosY() const{
        return PosY_n;
      }
      char getAvatar() const{
        return avatar;
      }
      WORD getCorNinho() const{
        return corNinho;
      }
      string getAntsInfo() const{
        ostringstream os;
        for(auto it=ants.begin(); it < ants.end();it++){
          os << (*it)->getInfo() << endl;
        }
        return os.str();
      }
      string getInfoGeral() const{
        ostringstream os;
        os << "Ninho " << getID() << endl;
        os << "Posicao: " << getPosX() << " " << getPosY() << endl;
        os << "---Informacoes gerais---" << endl;
        os << "Energia: " << getEnergy()<< endl;
        os << "Nova: " << getNova() << endl;
        os << "Transferencia: " << getTransfere() << endl;
        os << "Numero de formigas: " << ants.size() << "\n" << endl;
        return os.str();
      }
      void addFormigas(int x, int y);
     ~Nest();
     WORD getColor() const{return corNinho;}
};

#endif // NEST_H
