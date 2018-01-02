#include "includeme.h"
#include "Mundo.h"/*
void segundosComandos(config_t inicial){
  string command, param, arg1,arg2,arg3; //o parametro devera ser convertido para inteiro
  vector<string>comm_list;
    Mundo a(inicial.lim);
  comm_list=load_commands("command_simul.txt");
  cout << "Iniciando simulacão " << endl;
  do{
      cout << "[SIMUL]Insira comando.: para sair escreva 'sair'" << endl;
      getline(cin,command);  // getline para evitar problemas com buffers
      if (command == "sair"){
         cout << "[SIMUL] encerrando" << endl; return;
      }
      else if(check_command(command,comm_list)==true){ // agora falta fazer o "which command das simulações basicamente e as funções respetivas.
        if (command == "ninho"){
            do{
                cout << "Linha: ";
                getline(cin, arg1);
                cout << "\nColuna: ";
                getline(cin, arg2);
            }while(atoi(arg1.c_str()) >= 10 || atoi(arg2.c_str()) >= 10 || atoi(arg1.c_str()) < 0 || atoi(arg2.c_str()) < 0);
            Consola::clrscr();
            a.newNinho(inicial, atoi(arg1.c_str()), atoi(arg2.c_str())); // falta meter a imprimir
            Consola::gotoxy(0,15);
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "criaf"){
            cout << "Numero de formigas: ";
            getline(cin, arg1);
            cout << "\nID do ninho:";
            getline(cin, arg2);
            Consola::clrscr();
            a.addFormigas(atoi(arg1.c_str()), atoi(arg2.c_str())); //  falta meter a imprimir
            Consola::gotoxy(0,15);
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "cria1"){
            cout << "ID do ninho:";
            getline(cin, arg1);
            do{
                cout << "\nx:";
                getline(cin, arg2);
                cout << "\ny:";
                getline(cin, arg3);
            }while(atoi(arg2.c_str()) >= 10 || atoi(arg3.c_str()) >= 10 || atoi(arg2.c_str()) < 0 || atoi(arg3.c_str()) < 0);
            Consola::clrscr();
            a.addFormigas(1,atoi(arg1.c_str()),atoi(arg2.c_str()),atoi(arg3.c_str())); // fazemos uso dos argumentos por default de c++
            Consola::gotoxy(0,15);
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "listamundo"){
            Consola::clrscr();
            Consola::gotoxy(0,0);
            cout << a.getInfo(); // done
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "listaninho"){
            cout << "ID do ninho:";
            getline(cin, arg1);
            Consola::clrscr();
            Consola::gotoxy(0,0);
            cout << a.getNinho(atoi(arg1.c_str())); // done
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "listaposicao"){\
            cout << "X:";
            getline(cin, arg1);
            cout << "\nY:";
            getline(cin, arg2);
            if(a.verificaPos(atoi(arg1.c_str()),atoi(arg2.c_str()))==false){
                Consola::clrscr();
                Consola::gotoxy(0,0);
                cout << a.getInfoCoord(atoi(arg1.c_str()), atoi(arg2.c_str()));
            }
            else
                cout << "Posicao esta vazia";
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "tempo"){
            cout << "Numero de iteracoes: ";
            getline(cin, arg1);
            a.avancar(atoi(arg1.c_str()));
          }
    }
  }while(1);
}

/*int comandosSimul(const vector<string>&comm_list, const string &command, config_t inicial){
    Mundo a(inicial.lim);
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
      // a.avancar(atoi(arg1.c_str()));
    }
}*/
