#include "includeme.h"

double uniform01(int upper){
    static default_random_engine e;
    static uniform_real_distribution<double> u(0,upper);
    
    return u(e);
}
