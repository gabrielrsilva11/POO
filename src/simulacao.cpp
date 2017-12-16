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
      else if(check_command(command,comm_list)==true){ // agora falta fazer o "which command das simulações basicamente e as funções respetivas.
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
        Mundo::newNinho(inicial, arg1, arg2); // falta meter a imprimir
    }
    else if (command == "criaf"){
        cout << "Numero de formigas: ";
        getline(cin, arg1);
        cout << "\nID do ninho:";
        getline(cin, arg2);
        Mundo::addFormigas(arg1, arg2); //  falta meter a imprimir
    }
    else if (command == "cria1")}{
        cout << "ID do ninho:";
        getline(cin, arg1);
        cout << "\nx:";
        getline(cin, arg2);
        cout << "\ny:";
        getline(cin, arg3);
        Mundo::addFormigas(1,arg1,arg2,arg3); // fazemos uso dos argumentos por default de c++
    }
    else if (command == "listamundo"){
        cout << Mundo::getInfo(); // done
    }
    else if (command == "listaninho"){
        cout << "ID do ninho:";
        getline(cin, arg1);
        cout << Mundo::getNinho(arg1); // done
    }
    else if (command == "listaposicao"){\
        cout << "X:";
        getline(cin, arg1);
        cout << "\nY:";
        getline(cin, arg2);
        if(Mundo::verificaPos(arg1,arg2))
            cout << Mundo::getInfoCoord(arg1, arg2);
        else
            cout << "Posicao esta vazia"
    }
    else if (command == "tempo"){
        cout << "Numero de iteracoes: ";
        getline(cin, arg1);
        avancar(arg1);
    }
}
