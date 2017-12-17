#include "includeme.h"

int main(){
  string command, param; //o parametro devera ser convertido para inteiro
  vector<string>comm_list;
  int arg;
  comm_list=load_commands("command_mundo.txt"); //inicializa comandos
  string c, l;
  config_t configs;


  do{
  cout << "Insira comando.: para sair escreva 'sair'" << endl;
  getline(cin,command);  // getline para evitar problemas com buffers
  if (command == "sair") { cout << "encerrando" << endl; break; }
  else if(check_command(command,comm_list)==false){
    cout << "Comando invalido" << endl;
    return 0;
  }
  if (command != "executa" && command != "inicio"){ // se for executa ou inicio não vale a pena estar a pedir parâmetros
  cout << "Insira parametro.: " << endl; //vamos ter de passar isto para ler o comando todo de uma vez como em SO
  getline(cin,param);
  arg = atoi(param.c_str());
  cout << listaComandos(comm_list);
  }

  int num = whichCommand(comm_list, command, arg, configs);
  cout << "Num comando " << num << endl;

  cout << configs.lim << endl;
  cout << configs.energiaLim << endl;
  cout << configs.energiaNinho << endl;
  cout << configs.energiaTransf << endl;
  cout << configs.maxMigalhInst << endl;
  cout << configs.percentMigalh << endl;

  }while(1);


  return 0;

}
