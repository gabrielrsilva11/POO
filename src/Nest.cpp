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

void Nest::addFormigas(int num,int x, int y){
    ants.push_back(new Ant(50, x, y,10,8));
    Consola::gotoxy(x,y);
    cout << "*";
}


void Nest::andar(){
    int x,y;
    for(auto it=ants.begin();it<ninhos.end();it++){
        if( QUALQUER COISA QUE FAZ COM QUE AS FORMIGAS NAO PASSEM DOS LIMITES )
            (*it)->setPosX(uniform01(-8,8));
            (*it)->setPosY(uniform01(-8,8));
            QUALQUER COISA QUE METE 1 NA POSICAO MAPA[X][Y];
    }
}

