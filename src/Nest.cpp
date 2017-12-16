#include "Nest.h"
#include "Ant.h"

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
    int posx=1, posy=1; //temp
    for(int i=0;i<num;i++){
      if(x==-1){
   //     posx = uniform01(8);
     //   posy = uniform01(8-posx); // so pode andar raio 8 por isso o que andar no x temos de subtrair ao y que e o max que pode andar
      }
    ants.push_back(new Ant(50, posx, posy,10,8)); //10 e 8 sao os raios de visao e mov como ainda so e preciso 1 tipo de formiga pode ser assim por agora
  }
  /*
  PARA IMPRIMIR O NINHO NESTA POSICAO
  gotoxy(x, y);
  cout << Ant::getAvatar();*/
}
