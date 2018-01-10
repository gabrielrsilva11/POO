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

void Nest::addFormigas(int num,int x, int y,int limite){
    ants.push_back(new Ant(50, x, y,10,8,'*', limite));
    Consola::gotoxy(x,y);
    cout << "*";
}




/*void Nest::andar(){
    int posX,posY;
    for(auto it=ants.begin();it<ants.end();it++){
        do{
            posX=uniform01(-8,8);
            posY=uniform01(-8+posX,8-posX);
            cout << (*it)->getPosX()+posX << "   " << (*it)->getPosY()+posY << endl;
        }while((*it)->getPosX()+posX < (*it)->getLimite() && (*it)->getPosY()+posY < (*it)->getLimite() && (*it)->getPosX()+posX > 0 && (*it)->getPosX()+posX > 0);
            (*it)->setPosX((*it)->getPosX()+posX);
            (*it)->setPosY((*it)->getPosY()+posY);
            Consola::gotoxy((*it)->getPosX()+posX,(*it)->getPosY()+posY);
            cout << "*";
            Consola::getch();
    }
}*/
void Nest::andar(){
    int posX,posY;
    for(auto it=ants.begin();it<ants.end();it++){
        posX=uniform01(0,8);
        posY=uniform01(0,8);

        if(uniform01(0,100)< 50){
            posX = (*it)->getPosX() + posX;
            posX = (*it)->getPosY() + posY;
            if(posX>(*it)->getLimite())
                posX=(*it)->getLimite()-1;
            if(posY>(*it)->getLimite())
                posY=(*it)->getLimite()-1;
            (*it)->setPosX(posX);
            (*it)->setPosY(posY);
            Consola::gotoxy(posX,posY);
            cout << "*";
            Consola::getch();
        }
        else{
            posX = (*it)->getPosX() - posX;
            posX = (*it)->getPosY() - posY;
            if(posX<0)
                posX=0;
            if(posY<0)
                posY=0;
            (*it)->setPosX(posX);
            (*it)->setPosY(posY);
            Consola::gotoxy(posX,posY);
            cout << "*";
            Consola::getch();
        }
    }
}


void Nest::apagaFormigas(){
  for(auto it=ants.begin();it<ants.end();it++){
    delete(*it);
    it = ninhos.erase(it);
  }
}

bool Nest::addEnergyFormigas(int linh, int col, int add){
  for(auto it=ants.begin(); it < ants.end(); it++){
    if((*it)->getPosY() == linh && (*it)->getPosX() == col){
      (*it)->setEnergy(add);
      return true;
    }
  }
  return false;
}

bool Nest::mataFormigas(int linh, int col){
  for(auto it=ants.begin(); it < ants.end(); it++){
    if((*it)->getPosY() == linh && (*it)->getPosX() == col){
      delete(*it);
      v.erase(it);
    }
  }
}
