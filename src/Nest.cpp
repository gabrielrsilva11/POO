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

void Nest::addFormigas(int num,int linha, int coluna,int limite){
    ants.push_back(new Ant(50, linha, coluna,10,8,'*', limite));

}

void Nest::andar(int limite){
       int posX,posY;

   // int posX,posY;
    for(auto it=ants.begin();it<ants.end();it++){

            int random=uniform01(0,100);

        if(random< 50){

            (*it)->setColuna(uniform01(0,8),limite);
            posX=uniform01(0,8);
            posY=uniform01(0,8);
            //posX = (*it)->getColuna() + posX;
            //posY = (*it)->getLinha() + posY;
            if(posX >=(*it)->getLimite())
                posX=(*it)->getLimite()-1;
            if(posY >=(*it)->getLimite())
                posY=(*it)->getLimite()-1;
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

            posX=uniform01(-8,0);
            posY=uniform01(-8,0);
            //posX = (*it)->getColuna() - posX;
            //posY = (*it)->getLinha() - posY;
            if(posX<0)
                posX=0;
            if(posY<0)
                posY=0;
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
