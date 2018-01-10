#ifndef ANT_H
#define ANT_H

#include "includeme.h"
//#include "Regras.h"
class Regras;
class RegraFoge;

class Ant{
    int ID;
    static int counter;
    char tipo;

     int energy;
     Posicao posicao;
     //int coluna, linha; //movimento coordenadas
     int Rvisao,Rmov; //raio de vis�o e de movimento
     int limite;
     vector <Regras*> regras;

 public:
     Ant(int a=50, int li=0, int col=0, int d=0, int e=0, char f='E', int g=0):energy(a),posicao(li,col),Rvisao(d),Rmov(e),tipo(f), limite(g){
       ID = ++counter;
      /* if(b<limite && c <limite){
        PosX = b;
        PosY = c;
       }
       else{
        PosX = 0;
        PosY = 0;
       }*/
     }
     char getTipo() const{
       return tipo;
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
     int getColuna() const{
       return posicao.getColuna();
     }
     int getLinha() const{
       return posicao.getLinha();
     }
     int getRvisao() const{
       return Rvisao;
     }
     int getRmov() const{
       return Rmov;
     }
     string getInfo(){
       ostringstream os;
       os << "ID: " << getID() << " Energy: " << getEnergy() << " Pos: " << getLinha() << " " << getColuna() << " Raio Visao: " << getRvisao() << " Raio Mov: " << getRmov() << " Tipo: " << getTipo();
       return os.str();
     }
     void setEnergy(int add){
       energy += add;
     }
     void setColuna(int add,int lim){
        if (add <lim)
            posicao.setColuna(add);
     }
     void setLinha(int add,int lim){
      if (add <lim)
       posicao.setLinha(add);
     }

     bool verificaPos(int linh, int col){
        return posicao.verficaPos(linh,col);
      }

      void addRegra(Regras* a){
        regras.push_back(a);
      }
     ~Ant(){}//cout << "Formiga a morrer" << endl;

};


class Cuidadora:public Ant{
public:
  Cuidadora(int a=100, int b=0, int c=0, int d=5, int e=3, char f='C', int g=0);
};

class Vigilante:public Ant{
public:
  Vigilante(int a=150, int b=0, int c=0, int d=7, int e=5, char f='V', int g=0);
};

class Assaltante:public Ant{
public:
  Assaltante(int a=80, int b=0, int c=0, int d=8, int e=4, char f='A', int g=0);
};

class Exploradora:public Ant{
public:
  Exploradora(int a=200, int b=0, int c=0, int d=10, int e=8, char f='E', int g=0);
};

class FormigaGato:public Ant{}; //ultra formiga super poderosa



#endif // ANT_H
