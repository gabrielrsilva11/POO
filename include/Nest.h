#ifndef NEST_H
#define NEST_H

#include "includeme.h"
#include "Ant.h"



class Nest{
  static int counter;
  char avatar;
  int ID;
  int energy, energyAtual, nova, transfere;
  vector <Ant*> ants;
  Posicao posicao;
  WORD corNinho;
  public:
      Nest(int a, int b, int c, int d, int e, WORD cor, char f= 'O'):energy(a),nova(b),transfere(c),posicao(d,e),corNinho(cor),avatar(f){
        ID = ++counter;
        energyAtual=a;
      };
    vector <Ant*> getFormigas() const {return ants;}
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
      int getLinha() const{
        return posicao.getLinha();
      }
      int getColuna() const{
        return posicao.getColuna();
      }
      void setEnergyAtual(int add){
        energyAtual += add;
      }
      int getEnergyAtual() const{return energyAtual;}
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
        os << "Posicao: " << getLinha() << " " << getColuna() << endl;
        os << "---Informacoes gerais---" << endl;
        os << "Energia: " << getEnergyAtual()<< endl;
        os << "Nova: " << getNova() << endl;
        os << "Transferencia: " << getTransfere() << endl;
        os << "Numero de formigas: " << ants.size() << "\n" << endl;
        os << getAntsInfo();
        return os.str();
      }
      void andar(int limite,Mundo &m);

      void addFormigas(int num,int linha, int coluna, int limite, char tipo);

      ~Nest(){
        auto i=ants.begin();
            //cout << "Vou destruir formigas" << endl;
        for (; i<ants.end();i++){
                    //cout << "A formiga " << (*i)->getID() << " esta a ser destruidaaa" << endl;
                delete (*i);
        }

      };

      bool verificaPos(int linh, int col){
        return posicao.verficaPos(linh,col);
      }

      bool verificaPosFormigas(int linh, int col){
        for(auto it=ants.begin(); it < ants.end();it++){
                if((*it)->verificaPos(linh,col))
                    return true;

        }
      return false;
      }

      void apagaFormigas();
      bool addEnergyFormigas(int linh, int col, int add);
      bool mataFormigas(int linh, int col);
     WORD getColor() const{return corNinho;}
};

#endif // NEST_H
