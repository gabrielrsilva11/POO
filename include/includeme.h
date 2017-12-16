#ifndef includeme_H
#define includeme_H



/* --- Libraries and stuff */

#include <iostream>
#include <string>
#include <algorithm> //for the function count_spaces
#include <sstream>
#include <vector>
#include <fstream>
#include <random>
#include <cmath>
#include "Consola.h"

using namespace std;

typedef struct configuracao{
    int lim = -1, energiaNinho = -1, energiaLim =-1, energiaTransf=-1;
    int percentMigalh=-1, energiaMigalh=-1, maxMigalhInst=-1;
}config_t;

/* --- Command functions --- */
int space_count(const string& verify);
vector<string> load_commands(string ficheiro);
bool check_command(const string& command,const vector<string>&list);
bool check_existence(const string& command,const vector<string>&list);
string listaComandos(const vector<string>&comm_list);
int whichCommand(const vector<string>&comm_list, const string &command, int arg);
void leExecuta(const vector<string>&comm_list);
void segundosComandos(config_t inicial);
/* --- Uniform para aleatoriedade */ //funcoesGlobais.cpp
double uniform01(int upper);

#endif
