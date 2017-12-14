#ifndef includeme_H
#define includeme_H



/* --- Libraries and stuff */

#include <iostream>
#include <string>
#include <algorithm> //for the function count_spaces
#include <sstream>
#include <vector>
#include <fstream>

//#include "classes.h"

using namespace std;

/* --- Command functions --- */
int space_count(const string& verify);
vector<string> load_commands();
bool check_command(const string& command,const vector<string>&list);
bool check_existence(const string& command,const vector<string>&list);

#endif
