#ifndef POSICAO_H
#define POSICAO_H

#include "includeme.h"


class Posicao
{
    int linha,coluna;

    public:
        Posicao(int l,int c):linha(l),coluna(c){};
        int getLinha()const{return linha;}
        int getColuna()const{return coluna;}
        void setLinha(int n){linha=n;}
        void setColuna(int n){coluna=n;}

        bool raioAccao(int raio, int xAct, int yAct, int x1, int y1){
            int xAux=xAct-x1;
            int yAux=yAct-y1;
            if(std::max(abs(xAux),abs(yAux))<= raio){
                return true;
           }
            return false;
        }

        int moveEfectiv(int raio, int xAct, int yAct, int x1, int y1){
            int xAux=xAct-x1;
            int yAux=yAct-y1;
            return abs(xAux)+abs(yAux);
        }

        bool verficaPos (int l, int col){
            if (linha == l && coluna == col)
                return true; // está ocupada
            return false;
        }

        virtual ~Posicao(){};

};

#endif // POSICAO_H
