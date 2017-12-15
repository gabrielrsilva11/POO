#include "Nest.h"

Nest::Nest()
{
    //ctor
}

Nest::~Nest()
{
    //dtor
}

void Nest::addFormigas(int num){
  int posx,posy;
  for(int i=0; i<num; i++){
    posx = uniform01(8);
    posy = uniform01(8); // vai generar posicoes automaticamente e preciso ver se estao ocupadas depois
    ants.push_back(new Ant(50, posx, posy,10,8, getCorNinho())); //10 e 8 sao os raios de visao e mov como ainda so e preciso 1 tipo de formiga pode ser assim por agora
  }
}
