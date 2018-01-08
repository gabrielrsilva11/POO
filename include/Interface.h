#ifndef INTERFACE_H
#define INTERFACE_H

#include "includeme.h"
#include "Mundo.h"
#include "Ant.h"
#include "Nest.h"
#include "Migalha.h"

class Interface
{

        vector <Mundo*> m;
    public:
        Interface();
        virtual ~Interface();
        /* Fun��es b�sicas */
        void TamEcra(int x, int y) { Consola::setScreenSize(x,y);}
        void LimpaEcra(){ Consola::clrscr();}
        void PosiciCursor(int x, int y) { Consola::gotoxy(x,y);}
        void corTexto (WORD color) { Consola::setTextColor(color);}


        /* Para comandos */

        /* Carrega os comandos em ficheiro de texto */
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


        /* Pede um comando ao utilizador e verifica se � v�lido*/
        int SolicitaComando(const vector<string>&comm_list, Mundo &m){
            string command, param; //o parametro devera ser convertido para inteiro
            int arg;

          do{
              LimpaEcra();
              PosiciCursor(5,5);
              cout << "INSIRA COMANDO :     terminar - 'sair'  comandos disponiveis - 'help' " << endl;
              PosiciCursor(5,6);
              getline(cin,command);  // getline para evitar problemas com buffers


              if (command == "sair") {
                    PosiciCursor(5,7);
                    cout << "encerrando" << endl; break; }
              if(check_command(command,comm_list)==false){
                cout << "Comando invalido" << endl;
              }
             else {
                 if (command == "help") {
                    PosiciCursor(5,7);
                    int num = listaComandos(comm_list);
                    PosiciCursor(5,7+num);
                    cout << "Prima uma tecla para continuar" << endl;
                    getchar();
                 }

                  if (command != "executa" && command != "inicio" && command != "help"){ // se for executa ou inicio n�o vale a pena estar a pedir par�metros
                      PosiciCursor(5,7);
                      cout << "Insira parametro.: " << endl; //vamos ter de passar isto para ler o comando todo de uma vez como em SO
                      getline(cin,param);
                      arg = atoi(param.c_str());
                      //cout << listaComandos(comm_list);
                  }
              whichCommand(comm_list, command, arg,m);
              } //preenche a estrutura consoante o comando inserido
/*

              cout << configs.lim << endl;
              cout << configs.energiaLim << endl;
              cout << configs.energiaNinho << endl;
              cout << configs.energiaTransf << endl;
              cout << configs.maxMigalhInst << endl;
              cout << configs.percentMigalh << endl;
*/
          }while(1);

        }

        /* Verifica se um comando � v�lido */
        bool check_command(const string& command,const vector<string>&list){
          int spaces,exists;

          if((spaces = space_count(command))!=0) //primeiro conta os espa�os
            return false;

          if ((exists = check_existence(command,list))==false) //depois v� se existe
            return false;

          return true;
        }

        /* Verifica se um comando existe */
        bool check_existence(const string& command,const vector<string>&list){
          for(int i= 0;i<list.size();i++){
            if(command == list[i])
              return true;
          }
          return false;
        }


        /* Counts spaces */
        int space_count(const string& verify){
          int nspaces = 0;

          for (int i=0; i<verify.size();i++)
            if(verify[i] == ' ')
              nspaces++;

          return nspaces;
        }

        /* Apresenta na consola os comandos dispon�veis */
        int listaComandos(const vector<string>&comm_list){
            //ostringstream os;
            int i;
            cout << "lista de comandos disponiveis:" << endl;
            for(i= 0;i<comm_list.size();i++){
                PosiciCursor(5,8+i);//faz um print dos comandos no vector
                cout << comm_list[i] << endl;
            }
            return i;
        }


        void whichCommand(const vector<string>&comm_list, const string &command, int arg, Mundo &m){
      //  config_t inicial;
        if (command == "defmundo")
          if(arg <= 10 && arg > 0){
            m.criaMundo(arg);
            cout << m.getLimites() <<endl;
          }
          else{
            Consola::clrscr();
            Consola::gotoxy(0,15);
            cout << "Valor introduzido muito alto\nPrima uma tecla para tentar de novo";
            Consola::getch();
          }
        else if (command == "defen")
            m.setEnergNinho(arg);
        else if (command == "defpc")
            m.setEnergLim(arg);
        else if (command == "defvt")
            m.setEnergTransf(arg);
        else if (command == "defmi")
            if(arg <= 100 && arg >0)
              m.setPercentMig(arg);
            else
              cout << "Valor introduzido muito alto";
        else if (command == "defme")
            m.setEnergMig(arg);
        else if (command == "defnm")
            m.setMaxMig(arg);
        else if (command == "executa")
            leExecuta(comm_list,m);
        else if (command == "inicio"){ //descomentar para validar se os par�metros foram todos inseridos
            //if(inicial.lim != -1 && inicial.energiaLim != -1 && inicial.energiaTransf != -1 && inicial.energiaNinho != -1){ // mais tarde temos de adicionar aqui os comandos das migalhas
                LimpaEcra();
                ComandosSimul(m);}
            /*}
            else{
                Consola::clrscr();
                Consola::gotoxy(0,15);
                cout << "Ainda nao executou  todas as configuracoes iniciais\nPrima uma tecla para tentar de novo";
                Consola::getch();
            }*/

       ;
}
        /* Executa os comandos em ficheiro de texto*/
        int leExecuta(const vector<string>&comm_list,Mundo &m){
          ifstream fs ("executa.txt");
          string command;
          string arg;

          if(fs.is_open()){

              while(getline(fs,command)){ // temos de meter isto tudo numa linha mas sem os fscanf nao sei como se faz em c++
                getline(fs,arg);
                cout << "Li o comando " << command << " com o argumento " << arg << endl;
                if(check_command(command,comm_list)){ //verifica se o comando existe
                  if(command != "executa"){ // nao queremos entrar num loop infinito se estiver sempre a chamar "executa"
                    whichCommand(comm_list, command, atoi(arg.c_str()),m); // executa o comando lido
                    return 1;
                  }
                  else{
                    cout << "Este comando nao existe" << command << endl;
                    return 0;
                  }
                }
              }
          }
        }

        /* Fun��es para simula��o */
void ComandosSimul(Mundo &m){
  string command, param, arg1,arg2,arg3; //o parametro devera ser convertido para inteiro
  vector<string>comm_list;
  comm_list=load_commands("command_simul.txt");
  cout << "Iniciando simulac�o " << endl;
  do{
     LimpaEcra();
     ImprimeMundo(m);
     corTexto(Consola::CYAN_CLARO);
    PosiciCursor(5+m.getLimites()*4,5);
      cout << "[SIMUL]Insira comando.: para sair escreva 'sair'" << endl;
    PosiciCursor(5+m.getLimites()*4,6);
      getline(cin,command);  // getline para evitar problemas com buffers
      if (command == "sair"){
         cout << "[SIMUL] encerrando" << endl; return;
      }
      else if(check_command(command,comm_list)==true){ // agora falta fazer o "which command das simula��es basicamente e as fun��es respetivas.
        if (command == "ninho"){
            do{
                PosiciCursor(5+m.getLimites()*4,7);
                cout << "Linha: " << endl;
                   PosiciCursor(5+m.getLimites()*4,8);
                getline(cin, arg1);
                    PosiciCursor(5+m.getLimites()*4,9);
                cout << "Coluna: " << endl;
                    PosiciCursor(5+m.getLimites()*4,10);
                getline(cin, arg2);
            }while(atoi(arg1.c_str()) >= 10 || atoi(arg2.c_str()) >= 10 || atoi(arg1.c_str()) < 0 || atoi(arg2.c_str()) < 0);
            Consola::clrscr();
            m.newNinho(atoi(arg1.c_str()), atoi(arg2.c_str())); // falta meter a imprimir
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
            m.addFormigas(atoi(arg1.c_str()), atoi(arg2.c_str())); //  falta meter a imprimir
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
            m.addFormigas(1,atoi(arg1.c_str()),atoi(arg2.c_str()),atoi(arg3.c_str())); // fazemos uso dos argumentos por default de c++
            Consola::gotoxy(0,15);
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "listamundo"){
            Consola::clrscr();
            Consola::gotoxy(0,0);
            cout << m.getInfo(); // done
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "listaninho"){
            cout << "ID do ninho:";
            getline(cin, arg1);
            Consola::clrscr();
            Consola::gotoxy(0,0);
            cout << m.getNinho(atoi(arg1.c_str())); // done
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "listaposicao"){\
            cout << "X:";
            getline(cin, arg1);
            cout << "\nY:";
            getline(cin, arg2);
            if(m.verificaPos(atoi(arg1.c_str()),atoi(arg2.c_str()))==false){
                Consola::clrscr();
                Consola::gotoxy(0,0);
                cout << m.getInfoCoord(atoi(arg1.c_str()), atoi(arg2.c_str()));
            }
            else
                cout << "Posicao esta vazia";
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "tempo"){
            cout << "Numero de iteracoes: ";
            getline(cin, arg1);
            m.avancar(atoi(arg1.c_str()));
          }
    }
  }while(1);
}



        void ImprimeMundo(const Mundo &m){
           int lim = m.getLimites();
           corTexto(Consola::COR_DE_ROSA);
            for (int i = 0; i< lim; i++) {
                for (int j = 0; j<lim; j++) {
                PosiciCursor(5 + j * 3, 5 + i * 2);
                cout << "A";
                }
            }
            ImprimeNinho(m.getNinhos());
        }

        void ImprimeNinho (const vector <Nest*> &ninhos){
            int PosX, PosY;
            for(auto it=ninhos.begin(); it<ninhos.end(); it++){
                corTexto(Consola::AMARELO);
                PosX =(*it)->getPosX();
                PosY =(*it)->getPosY();
                PosiciCursor(5 + PosY * 3, 5 + PosX * 2);
                cout << (*it)->getAvatar();
                corTexto(Consola::VERMELHO);
                ImprimeFormigas((*it)->getFormigas());
            }


        }

        void ImprimeFormigas (const vector <Ant*> &formigas){
            int PosX, PosY;
            for(auto it=formigas.begin(); it<formigas.end(); it++){
                PosX =(*it)->getPosX();
                PosY =(*it)->getPosY();
                PosiciCursor(5 + PosY * 3, 5 + PosX * 2);
                cout << (*it)->getAvatar();
            }

        }


};

#endif // INTERFACE_H
