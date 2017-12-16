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

/*
void Nest::addFormigas(int num){
  int posx,posy;
  for(int i=0; i<num; i++){
    posx = uniform01(8);
    posy = uniform01(8); // vai generar posicoes automaticamente e preciso ver se estao ocupadas depois
    ants.push_back(new Ant(50, posx, posy,10,8, getCorNinho())); //10 e 8 sao os raios de visao e mov como ainda so e preciso 1 tipo de formiga pode ser assim por agora
  }
}
*/ // O protótipo do constructor da formiga estava mal
void Nest::addFormigas(int num){
  int posx,posy;
  for(int i=0; i<num; i++){
    posx =1;
    posy =1; //temporario
 //   posx = uniform01(8);
   // posy = uniform01(8); // vai gerar posicoes automaticamente e preciso ver se estao ocupadas depois
    ants.push_back(new Ant(50, posx, posy,10,8)); //10 e 8 sao os raios de visao e mov como ainda so e preciso 1 tipo de formiga pode ser assim por agora
  }
}
