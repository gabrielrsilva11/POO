#ifndef MUNDO_H
#define MUNDO_H

#include "Nest.h"
#include "Ant.h"
#include "Migalha.h"
#include "includeme.h"

class Mundo
{
    int limite;
    vector <Nest*> ninhos;
    int **mapa;

    public:
        Mundo(int limite){
            mapa = new int*[limite];
            for(int i=0; i < limite ; i++){
                mapa[i]= new int[limite];
            }  //n�o esquecer de fazer free
        };
        void setMapa(int x,int y){
            mapa[x][y]=1;
        }
        string getInfo() const;
        void newNinho(config_t inicial, int x, int y);
        void addFormigas(int num, int ID ,int x = -1,int y = -1);
        string getNinho(int ID) const;
        bool verificaPos(int x, int y);
        string getInfoCoord(int x, int y);
        void avancar(int num);
        string getInfoAntsNinho(int ID) const;
        ~Mundo(){
            for(int i=0;i<limite;i++){
                //delete[] mapa[i]; //não está a funcionar
            }
            delete[] mapa;

            auto i=ninhos.begin();
            //cout << "Vou destruir" << endl;
                for (; i<ninhos.end();i++){
                    //cout << "O ninho " << (*i)->getID() << " esta a ser destruido" << endl;
                    delete (*i);
                }
        }

};

#endif // MUNDO_H
