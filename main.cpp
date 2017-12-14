#include "includeme.h"

int main(){
  string command, param; //o parametro devera ser convertido para inteiro
  vector<string>comm_list;
  int arg;
  comm_list=load_commands(); //inicializa comandos
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
  cout << "Insira parametro.: " << endl; //vamos ter de passar isto para ler o comando todo de uma vez como em SO
  getline(cin,param);
  arg = atoi(param);
  cout << listaComandos(comm_list);

  int num = whichCommand(comm_list, command, arg);
  cout << "Num comando " << num << endl;

  }while(1);


  return 0;

}
