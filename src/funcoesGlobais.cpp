#include "includeme.h"


/*
int** criaMundo (int limite){
    int mundo**=new int*[limite];
    for (int i=0; i<limite ; i++)
        mundo[i]=new int[limite];
    return mundo;
}
*/



double uniform01(){
    static default_random_engine e;
    static uniform_real_distribution<double> u(0.0,1.0);

}
