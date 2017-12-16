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
            mapa= new int*[limite]
            for(int i=0; i < limite ; i++){
                mapa[i]= new int[limite]
            };  //não esquecer de fazer free
        };
        void setMapa(int x,int y){
            mapa[x][y]=1;
        }
        virtual ~Mundo();

    protected:

    private:
};

#endif // MUNDO_H
