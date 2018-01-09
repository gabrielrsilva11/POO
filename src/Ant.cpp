#include "Ant.h"

/* Classe base */

int Ant::counter=0;
/*Ant::Ant()
{
    //ctor
}*/



/*Ant::~Ant()
{
    //dtor
}
*/

/*  Cuidadora */

/*  Outras formigas por aqui abaixo */

Cuidadora::Cuidadora(int a, int b, int c, int d, int e, char f, int g):Ant(a,b,c,d,e,f,g){
    addRegra(new RegraFoge);
    addRegra(new RegraComeMigalha);
    addRegra(new RegraProcuraMigalha);
    addRegra(new RegraVaiParaNinho);
    addRegra(new RegraPasseia);
}

Vigilante::Vigilante(int a, int b, int c, int d, int e, char f, int g):Ant(a,b,c,d,e,f,g){
    addRegra(new RegraProtege);
    addRegra(new RegraComeMigalha);
    addRegra(new RegraProcuraMigalha);
    addRegra(new RegraPasseia);
}


Assaltante::Assaltante(int a, int b, int c, int d, int e, char f, int g):Ant(a,b,c,d,e,f,g){
    addRegra(new RegraAssalta);
    addRegra(new RegraPersegue);
    addRegra(new RegraComeMigalha);
    addRegra(new RegraProcuraMigalha);
    addRegra(new RegraPasseia);
}

Exploradora::Exploradora(int a, int b, int c, int d, int e, char f, int g):Ant(a,b,c,d,e,f,g){
    addRegra(new RegraComeMigalha);
    addRegra(new RegraPasseia);
}
