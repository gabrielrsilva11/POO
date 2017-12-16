#include "includeme.h"
#include "Mundo.h"
void segundosComandos(config_t inicial){
  string command, param; //o parametro devera ser convertido para inteiro
  vector<string>comm_list;

  comm_list=load_commands("command_simul.txt");
  cout << "Iniciando simulacão " << endl;
  do{
      cout << "[SIMUL]Insira comando.: para sair escreva 'sair'" << endl;
      getline(cin,command);  // getline para evitar problemas com buffers
      if (command == "sair"){
         cout << "[SIMUL] encerrando" << endl; break;
      }
      else if(check_command(command,comm_list)==true){ // agora falta fazer o "which command das simulações basicamente e as funções respetivas.
        comandosSimul(comm_list, command, inicial);
      }
  }while(1);
}

int comandosSimul(const vector<string>&comm_list, const string &command, config_t inicial){
    Mundo a; // temp
    string arg1, arg2,arg3;
    if (command == "ninho"){
        cout << "Linha: ";
        getline(cin, arg1);
        cout << "\nColuna: ";
        getline(cin, arg2);
        a.newNinho(inicial, atoi(arg1.c_str()), atoi(arg2.c_str())); // falta meter a imprimir
    }
    else if (command == "criaf"){
        cout << "Numero de formigas: ";
        getline(cin, arg1);
        cout << "\nID do ninho:";
        getline(cin, arg2);
        a.addFormigas(atoi(arg1.c_str()), atoi(arg2.c_str())); //  falta meter a imprimir
    }
    else if (command == "cria1"){
        cout << "ID do ninho:";
        getline(cin, arg1);
        cout << "\nx:";
        getline(cin, arg2);
        cout << "\ny:";
        getline(cin, arg3);
        a.addFormigas(1,atoi(arg1.c_str()),atoi(arg2.c_str()),atoi(arg3.c_str())); // fazemos uso dos argumentos por default de c++
    }
    else if (command == "listamundo"){
        cout << a.getInfo(); // done
    }
    else if (command == "listaninho"){
        cout << "ID do ninho:";
        getline(cin, arg1);
        cout << a.getNinho(atoi(arg1.c_str())); // done
    }
    else if (command == "listaposicao"){\
        cout << "X:";
        getline(cin, arg1);
        cout << "\nY:";
        getline(cin, arg2);
        if(a.verificaPos(atoi(arg1.c_str()),atoi(arg2.c_str())))
            cout << a.getInfoCoord(atoi(arg1.c_str()), atoi(arg2.c_str()));
        else
            cout << "Posicao esta vazia";
    }
    else if (command == "tempo"){
        cout << "Numero de iteracoes: ";
        getline(cin, arg1);
       // avancar(atoi(arg1.c_str()));
    }
}
