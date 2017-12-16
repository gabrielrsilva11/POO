#include "includeme.h"

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
      else if(check_command(command,comm_list)==true){ // agora falta fazer o "which command das simula��es basicamente e as fun��es respetivas.
        comandosSimul(comm_list, command, inicial);
      }
  }while(1);
}

int (const vector<string>&comm_list, const string &command, config_t inicial){
    int arg1, arg2;
    if (command == "ninho"){
        cout << "Linha: ";
        getline(cin, arg1);
        cout << "\nColuna: ";
        getlin(cin, arg2);
        Mundo::newNinho(inicial, arg1, arg2); // funcao do mundo tenho que adicionar depois
    }
    else if (command == "criaf"){
        cout << "Numero de formigas: ";
        getline(cin, arg1);
        cout << "\nID do ninho:";
        getline(cin, arg2);
        Mundo::addFormigas(arg1, arg2);
    }
    else if (command == "cria1")}{
        getline(cin, arg1);
        cout << "\nID do ninho:";
        getline(cin, arg2);
    }

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
