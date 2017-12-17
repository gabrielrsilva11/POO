#include "includeme.h"
#include "Ant.h"
#include "Nest.h"
#include "Mundo.h"

int uniform01(int lower, int upper){
    static default_random_engine e;
    static uniform_int_distribution<int> u(lower,upper);

    return u(e);
}


int main(){
  string command, param; //o parametro devera ser convertido para inteiro
  vector<string>comm_list;
  int arg;
  comm_list=load_commands("command_mundo.txt"); //inicializa comandos
  string c, l;
  config_t configs;
  Mundo m(10);
  //m.newNinho(configs,20,30);
  //m.newNinho(configs,40,50);
  //m.addFormigas(10,2,10,30);

  //Nest b(12,20,30,40,50,(Consola::AZUL));

  //cout << m.getInfo() << endl;
  //cout << m.getNinho(1) << endl;
  //cout << m.getNinho(2) << endl;
  //cout << m.getInfoAntsNinho(2) << endl;

  //cout << b.getInfoGeral() << endl;


  do{
    Consola::clrscr();
    Consola::gotoxy(0,15);
  cout << "Insira comando.: para sair escreva 'sair'" << endl;
  getline(cin,command);  // getline para evitar problemas com buffers
  if (command == "sair") {
        cout << "encerrando" << endl; break; }
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
