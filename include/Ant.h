#ifndef ANT_H
#define ANT_H

#include "includeme.h"

class Ant{
 static int counter;
 int ID;
 int energy;
 int PosX, PosY; //movimento coordenadas
 int Rvisao,Rmov; //raio de vis�o e de movimento
 public:
     Ant(int a=50, int b=0, int c=0, int d=0, int e=0):energy(a),PosX(b), PosY(c),Rvisao(d),Rmov(e){
       ID = ++counter;
     };
     int getID() const{
       return ID;
     }
     int getEnergy() const{
       return energy;
     }
     int getPosX() const{
       return PosX;
     }
     int getPosY() const{
       return PosY;
     }
     int getRvisao() const{
       return Rvisao;
     }
     int getRmov() const{
       return Rmov;
     }
     string getInfo(){
       ostringstream os;
       os << "ID: " << getID() << " Energy: " << getEnergy() << " Pos: " << getPosX() << " " << getPosY() << " Raio Visao: " << getRvisao() << " Raio Mov: " << getRmov();
       return os.str();
     }
     void setEnergy(int add){
       energy += add;
     }
     void setPosX(int add){
       PosX += add;
     }
     void setPosY(int add){
       PosY +=add;
     }
     ~Ant();
};


class Cuidadora:public Ant{};
class Vigilante:public Ant{};
class Assaltante:public Ant{};
class Exploradora:public Ant{};
class FormigaGato:public Ant{}; //ultra formiga super poderosa

#endif // ANT_H
