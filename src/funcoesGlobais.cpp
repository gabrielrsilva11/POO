#include "includeme.h"

double uniform01(){
    static default_random_engine e;
    static uniform_real_distribution<double> u(0.0,1.0);

}
