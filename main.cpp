#include "includeme.h"

int main(){
  string command;
  vector<string>comm_list;

  comm_list=load_commands();

  /* REMOVE LATER -- Just testing this */
  cout << "[TESTE] Insira um comando: ";

  getline(cin,command); //because cin >> can't read spaces, seriously -_-'
  if(check_command(command,comm_list)==false)
    cout << "Comando invalido" << endl;

  for(int i= 0;i<comm_list.size();i++){
    cout << comm_list[i] << endl;
  }

  return 0;

}
