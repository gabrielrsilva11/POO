#include "includeme.h"
#include "Ant.h"
#include "Nest.h"
#include "Mundo.h"
#include "Interface.h"


int uniform01(int lower, int upper){
    srand (time(NULL));
    time_t seed = time(nullptr);
    static default_random_engine e(seed);
    static uniform_int_distribution<int> u{lower,upper};
    return u(e);
}


int main(){


    Interface a;
    vector<string>comm_list;
    comm_list=a.load_commands("command_mundo.txt");

    a.TamEcra(100,100);
    Mundo m;
    a.SolicitaComando(comm_list,m);


    return 0;

}
