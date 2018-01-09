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

    vector <Nest*> ninhos;
    vector <Migalha*> migalhas;


    public:
        Mundo(){
        };
        void criaMundo(int lim){
            limite = lim;
            /*mapa = new int*[lim];
            for(int i=0; i < lim ; i++){
                mapa[i]= new int[lim];
            }  //n�o esquecer de fazer free
            for (int i=0; i < lim ; i++){
                for (int j=0; j<lim; j++)
                    mapa[i][j]=0;*/
         //   }
        }
       /* void setMapa(int x,int y){
            mapa[x][y]=1;
        }*/
        void setEnergNinho (int x){energiaNinho = x;}
        void setEnergLim (int x){energiaLim = x;}
        void setEnergTransf (int x){energiaTransf = x;}
        void setPercentMig (int x){percentMigalh = x;}
        void setEnergMig (int x){energiaMigalh = x;}
        void setMaxMig (int x){maxMigalhInst = x;}
       int getMaxMigalhInst() const{
          return maxMigalhInst;
        }
        int getEnergNinho (){return energiaNinho;}
        int getEnergLim (){ return energiaLim;}
        int getEnergTransf (){ return energiaTransf;}
        int getPercentMig (){return percentMigalh;}
        int getEnergMig (){return energiaMigalh;}
        int getMaxMig (){return maxMigalhInst;}
        string getInfo() const;
        int getLimites() const {return limite;}
        void newNinho( int x, int y);
        void addFormigas(int num, int ID ,int linha = -1,int coluna = -1);
        string getNinho(int ID) const;

        string getInfoCoord(int x, int y);

        void MigalhasIniciais(int percInicial, int energiaInic);
        void SpawnMigalha();
        Migalha* getMigalhaElemento(int i);
        void apagaMigalha(int i);
        void removeMigalha();
        int getMigalhasSize() {return migalhas.size();}
        void iteracoes(int num);


        vector <Nest*> getNinhos() const {return ninhos;}
        string getInfoAntsNinho(int ID) const;
        ~Mundo(){

            auto i=ninhos.begin();
            //cout << "Vou destruir" << endl;
                for (; i<ninhos.end();i++){
                    //cout << "O ninho " << (*i)->getID() << " esta a ser destruido" << endl;
                    delete (*i);
                }
        }

};

#endif // MUNDO_H
