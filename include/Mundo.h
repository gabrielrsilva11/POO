#ifndef MUNDO_H
#define MUNDO_H

#include "Nest.h"
#include "Ant.h"
#include "Migalha.h"
#include "includeme.h"

class Mundo
{

    int limite = -1, energiaNinho = -1, energiaLim =-1, energiaTransf=-1;
    int percentMigalh=-1, energiaMigalh=-1, maxMigalhInst=-1;
    vector <Migalha*> migalhas;
    vector <Nest*> ninhos;
    int **mapa;

    public:
        Mundo(){
        };
        void criaMundo(int lim){
            limite = lim;
            mapa = new int*[lim];
            for(int i=0; i < lim ; i++){
                mapa[i]= new int[lim];
            }  //n�o esquecer de fazer free
        }
        void setMapa(int x,int y){
            mapa[x][y]=1;
        }
        void removeMapa(int x,int y){
          mapa[x][y]=0;
        }
        void setEnergNinho (int x){energiaNinho = x;}
        void setEnergLim (int x){energiaLim = x;}
        void setEnergTransf (int x){energiaTransf = x;}
        void setPercentMig (int x){percentMigalh = x;}
        void setEnergMig (int x){energiaMigalh = x;}
        void setMaxMig (int x){maxMigalhInst = x;}
        int getMaxMigalhInst() const{
          return maxMigalhInst;
        }
        string getInfo() const;
        int getLimites() const {return limite;}
        void newNinho( int x, int y);
        void addFormigas(int num, int ID ,int x = -1,int y = -1);
        string getNinho(int ID) const;
        bool verificaPos(int x, int y);
        string getInfoCoord(int x, int y);
        void avancar(int num);
        vector <Nest*> getNinhos() const {return ninhos;}
        string getInfoAntsNinho(int ID) const;
        void MigalhasIniciais(int percInicial, int energiaInic);
        void SpawnMigalha();
        Migalha* getMigalhaElemento(int i);
        void apagaMigalha(int i);
        void removeMigalha();
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
