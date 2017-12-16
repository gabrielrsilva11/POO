#ifndef MUNDO_H
#define MUNDO_H

#include "Nest.h"
#include "Ant.h"
#include "Migalha.h"

class Mundo
{
    static int limite;
    vector <Nest*> ninhos;
    int **mapa;
    public:
        Mundo(){
            mapa= new int*[limite]
            for(int i=0; i < limite ; i++){
                mapa[i]= new int[limite]
            };  //n�o esquecer de fazer free
        };
        void setMapa(int x,int y){
            mapa[x][y]=1;
        }
        string getInfo() const
        void newNinho(config_t inicial, int x, int y);
        void addFormigas(int num, int ID , x = -1, y = -1);
        string getNinho(int ID) const;
        bool verificaPos(int x, int y);
        string getInfoCoord(int x, int y);
        virtual ~Mundo();
    protected:

    private:
};

#endif // MUNDO_H
