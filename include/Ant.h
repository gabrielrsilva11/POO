#ifndef ANT_H
#define ANT_H

#include "includeme.h"

class Ant{
 static int counter;
 char Avatar;
 int ID;
 int energy;
 int PosX, PosY; //movimento coordenadas
 int Rvisao,Rmov; //raio de vis�o e de movimento
 int limite;
 int comunidade;
 vector <Regras*> regras;
 public:
     Ant(int a=50, int b=0, int c=0, int d=0, int e=0, char f='*', int g=0):energy(a),PosX(b), PosY(c),Rvisao(d),Rmov(e),Avatar(f), limite(g){
       ID = ++counter;
     };
     char getAvatar() const{
       return Avatar;
     }
     int getID() const{
       return ID;
     }
     int getEnergy() const{
       return energy;
     }
     int getLimite() const{
        return limite;
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
     int getComunidade() const{
       return Comunidade;
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
     ~Ant(){//cout << "Formiga a morrer" << endl;
     };
};

class Cuidadora:public Ant{
public:
  Cuidadora(int a=100, int b=0, int c=0, int d=5, int e=3, char f='*', int g=0):Ant(a,b,c,d,e,f,g){
    ID = ++counter;
    regras.push_back(new RegraFoge);
    regras.push_back(new RegraComeMigalha);
    regras.push_back(new RegraProcuraMigalha);
    regras.push_back(new RegraVaiParaNinho);
    regras.push_back(new RegraPasseia);
  }
};
class Vigilante:public Ant{
public:
  Vigilante(int a=150, int b=0, int c=0, int d=7, int e=5, char f='*', int g=0):Ant(a,b,c,d,e,f,g){
    ID = ++counter;
    regras.push_back(new RegraProtege);
    regras.push_back(new RegraComeMigalha);
    regras.push_back(new RegraProcuraMigalha);
    regras.push_back(new RegraPasseia);
  }
};
class Assaltante:public Ant{
public:
  Assaltante(int a=80, int b=0, int c=0, int d=8, int e=4, char f='*', int g=0):Ant(a,b,c,d,e,f,g){
    ID = ++counter;
    regras.push_back(new RegraAssalta);
    regras.push_back(new RegraPersegue);
    regras.push_back(new RegraComeMigalha);
    regras.push_back(new RegraProcuraMigalha);
    regras.push_back(new RegraPasseia);
  }
};
class Exploradora:public Ant{
  Assaltante(int a=200, int b=0, int c=0, int d=10, int e=8, char f='*', int g=0):Ant(a,b,c,d,e,f,g){
    ID = ++counter;
    regras.push_back(new RegraComeMigalha);
    regras.push_back(new RegraPasseia);
  }
};
class FormigaGato:public Ant{}; //ultra formiga super poderosa

#endif // ANT_H
