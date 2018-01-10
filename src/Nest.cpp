#include "Nest.h"
#include "Ant.h"
#include "Mundo.h"


/*Nest::Nest()
{
    //ctor
}

Nest::~Nest()
{
    //dtor
}*/
int Nest::counter=0; //para evitar o multiple definition no .h

void Nest::addFormigas(int num,int linha, int coluna,int limite,char tipo){
    ants.push_back(new Ant(50, linha, coluna,10,8,tipo, limite));

}

void Nest::andar(int limite,Mundo &m){
    int posX,posY;


    for(auto it=ants.begin();it<ants.end();it++){

            int random=uniform01(0,100);

        if(random< 50){
            do{
            //(*it)->setColuna(uniform01(0,8),limite);
                posX=uniform01(0,8);
                posY=uniform01(0,8);
                //posX = (*it)->getColuna() + posX;
                //posY = (*it)->getLinha() + posY;
                if(posX >=(*it)->getLimite())
                    posX=(*it)->getLimite()-1;
                if(posY >=(*it)->getLimite())
                    posY=(*it)->getLimite()-1;
            }while(m.verificaPos(posY,posX));//se estiver livre dá false
           // if(mapa [posX][posY] == 0){
            (*it)->setColuna(posX,limite-1);
            (*it)->setLinha(posY,limite-1);

                // mapa [posX][posY] == 1;
            //}

            //Consola::gotoxy(posX,posY);
            //cout << "*";
            //Consola::getch();
        }
        else{
            do{
                posX=uniform01(-8,0);
                posY=uniform01(-8,0);
                //posX = (*it)->getColuna() - posX;
                //posY = (*it)->getLinha() - posY;
                if(posX<0)
                    posX=0;
                if(posY<0)
                    posY=0;
            }while(m.verificaPos(posY,posX));
            //if(mapa [posX][posY] == 0){
            (*it)->setColuna(posX,limite-1);
            (*it)->setLinha(posY,limite-1);
                //mapa[posX][posY] == 1;
            //}
            //Consola::gotoxy(posX,posY);
            //cout << "*";
            //Consola::getch();
        }
       // }while (posX >= limite || posY >= limite );
    }

//    return mapa;
}

void Nest::apagaFormigas(){
  for(auto it=ants.begin();it<ants.end();it++){
    delete(*it);
    it = ants.erase(it);
  }
}

bool Nest::addEnergyFormigas(int linh, int col, int add){
  for(auto it=ants.begin(); it < ants.end(); it++){
    if((*it)->getLinha() == linh && (*it)->getColuna() == col){
      (*it)->setEnergy(add);
      return true;
    }
  }
  return false;
}

bool Nest::mataFormigas(int linh, int col){
  for(auto it=ants.begin(); it < ants.end(); it++){
    if((*it)->getLinha() == linh && (*it)->getColuna() == col){
      delete(*it);
      ants.erase(it);
    }
  }
}
