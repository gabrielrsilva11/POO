#include "includeme.h"

/* Reads commands from .txt file */
vector<string> load_commands(string ficheiro){
  vector<string>comm_list;
  ifstream fs;
  string command;
  fs.open(ficheiro);

  while(getline(fs, command)){
    comm_list.push_back(command);
  }

  fs.close();
  return comm_list;
}

/* Takes care of everything concerning the validity of commands */
bool check_command(const string& command,const vector<string>&list){
  int spaces,exists;

  if((spaces = space_count(command))!=0)
    return false;

  if ((exists = check_existence(command,list))==false)
    return false;

  return true;
}

/* Checks if the command exists in the command_list.txt file */
bool check_existence(const string& command,const vector<string>&list){
  for(int i= 0;i<list.size();i++){
    if(command == list[i])
      return true;
  }
  return false;
}

string listaComandos(const vector<string>&comm_list){
    ostringstream os;
    for(int i= 0;i<comm_list.size();i++) //faz um print dos comandos no vector
    os << comm_list[i] << endl;
    return os.str();
}

int whichCommand(const vector<string>&comm_list, const string &command, int arg){
    config_t inicial;
    if (command == "defmundo")
      if(arg <= 10 && arg > 0)
        inicial.lim = arg;
      else
        cout << "Valor introduzido muito alto";
    if (command == "defen")
        inicial.energiaNinho = arg;
    if (command == "defpc")
        inicial.energiaLim = arg;
    if (command == "defvt")
        inicial.energiaTransf = arg;
    if (command == "defmi")
        if(arg <= 100 && arg >0)
          inicial.percentMigalh = arg;
        else
          cout << "Valor introduzido muito alto";
    if (command == "defme")
        inicial.energiaMigalh = arg;
    if (command == "defnm")
        inicial.maxMigalhInst = arg;
    if (command == "executa")
        leExecuta(comm_list);
    if (command == "inicio")
        segundosComandos(inicial); //ainda nao esta feita porque nao estou a ver bem como fazer
        return 9;
}

/* Counts spaces */
int space_count(const string& verify){
  int nspaces = 0;

  for (int i=0; i<verify.size();i++)
    if(verify[i] == ' ')
      nspaces++;

  return nspaces;
}

void leExecuta(const vector<string>&comm_list){
  ifstream fs ("executa.txt");
  string command;
  string arg;

  if(fs.is_open()){

      while(getline(fs,command)){ // temos de meter isto tudo numa linha mas sem os fscanf nao sei como se faz em c++
        getline(fs,arg);
        if(check_command(command,comm_list)){ //verifica se o comando existe
          if(command != "executa") // nao queremos entrar num loop infinito se estiver sempre a chamar "executa"
            whichCommand(comm_list, command, atoi(arg.c_str())); // executa o comando lido
          else{
            cout << "Este comando nao existe";
            return;
          }
        }
      }
  }
}

void segundosComandos(config_t inicial){
  string command, param; //o parametro devera ser convertido para inteiro
  vector<string>comm_list;
  comm_list=load_commands("command_simul.txt");

  do{
      cout << "Insira comando.: para sair escreva 'sair'" << endl;
      getline(cin,command);  // getline para evitar problemas com buffers
      if (command == "sair"){
         cout << "encerrando" << endl; break;
      }
      else if(check_command(command,comm_list)==false){ // agora falta fazer o "which command das simulações basicamente e as funções respetivas.
        cout << "Comando invalido" << endl;
        return;
      }
  }while(1);
}
