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
      Nest(int a, int b, int c, int d, int e, WORD cor, char f= 'O'):energy(a),nova(b),transfere(c),PosX_n(d),PosY_n(e),corNinho(cor),avatar(f){
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
<<<<<<< HEAD
      void andar();
      void addFormigas(int num,int x, int y, int limite);
      ~Nest(){};
=======
      void addFormigas(int num,int x, int y);
     //~Nest();
>>>>>>> a8bd97c6ac2f86ac1d03a0b416a802d30dbe09b6
     WORD getColor() const{return corNinho;}
};

#endif // NEST_H
