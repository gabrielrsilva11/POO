#ifndef MUNDO_H
#define MUNDO_H

#include "Nest.h"
#include "Ant.h"
#include "Migalha.h"

class Mundo
{
    static int limite;
    int **mapa;
    public:
        Mundo(){
            int tam = limite*limite;
            *mapa= new int [tam];  //não esquecer de fazer free
        };
        void setMapa(int x,int y){
            mapa[x][y]=1;
        }
        virtual ~Mundo();

    protected:

    private:
};

#endif // MUNDO_H
