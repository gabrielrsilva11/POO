#ifndef INTERFACE_H
#define INTERFACE_H

#include "includeme.h"
#include "Mundo.h"
#include "Ant.h"
#include "Nest.h"
#include "Migalha.h"

class Interface
{

        Mundo m; //assumindo que só vai existir um mundo de cada vez;
    public:
        Interface();
        virtual ~Interface();
        /* Funções básicas */
        void TamEcra(int x, int y) { Consola::setScreenSize(x,y);}
        void LimpaEcra(){ Consola::clrscr();}
        void PosiciCursor(int x, int y) { Consola::gotoxy(x,y);}
        void corTexto (WORD color) { Consola::setTextColor(color);}
        void corBack (WORD color) {Consola::setBackgroundColor(color);}


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


        /* Pede um comando ao utilizador e verifica se é válido*/
        int SolicitaComando(const vector<string>&comm_list, Mundo &m){
            string comandoint, command,param; //o parametro devera ser convertido para inteiro
            string arg;

          do{
              corBack(Consola::PRETO);
              LimpaEcra();
              listaComandos(comm_list);
              PosiciCursor(5,5);
              corTexto(Consola::COR_DE_ROSA);
              cout << "INSIRA COMANDO E PARAMETRO :  terminar - 'sair'" << endl;
              PosiciCursor(5,6);
              getline(cin,comandoint);  // getline para evitar problemas com buffers
              istringstream iss(comandoint);
              iss >> (command);
              iss >> (param);

              if (command == "sair") {
                    PosiciCursor(5,7);
                    cout << "encerrando" << endl; break; }
              if(check_command(command,comm_list)==false){
                cout << "Comando invalido" << endl;
              }
             else {

                  if (command != "executa" && command != "inicio"){ // se for executa ou inicio não vale a pena estar a pedir parâmetros
                      PosiciCursor(5,7);
                     // cout << "Insira parametro.: " << endl; //vamos ter de passar isto para ler o comando todo de uma vez como em SO
                     // PosiciCursor(5,8);
                      //getline(cin,param);
                      arg = param;
                      //cout << listaComandos(comm_list);
                  }
                  arg = param;
              whichCommand(comm_list, command, arg,m);
              } //preenche a estrutura consoante o comando inserido

          }while(1);

        }

        /* Verifica se um comando é válido */
        bool check_command(const string& command,const vector<string>&list){
          int spaces,exists;

          if((spaces = space_count(command))!=0) //primeiro conta os espaços
            return false;

          if ((exists = check_existence(command,list))==false) //depois vê se existe
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

        /* Apresenta na consola os comandos disponíveis */
        void listaComandos(const vector<string>&comm_list){
            //ostringstream os;
            corTexto(Consola::BRANCO);
            PosiciCursor(64,17);
            cout << '-';
            PosiciCursor(65,17);
            int i;
            cout << "lista de comandos disponiveis:" << endl;
            PosiciCursor(95,17);
            cout << '-';
            for(i= 0;i<comm_list.size();i++){
                PosiciCursor(75,18+i);//faz um print dos comandos no vector
                cout << comm_list[i] << endl;
            }
            for (int j = 0; j<i; j++){
                PosiciCursor(63,18+j);
                cout << '|';
            }
            for (int j = 0; j<i; j++){
                PosiciCursor(95,18+j);
                cout << '|';
            }
            for (int j = 0; j<(95-64) ; j++ ){
                PosiciCursor(64+j,18+i);
                cout << '-';
            }

        }


        void whichCommand(const vector<string>&comm_list, const string &command, const string &arg, Mundo &m){
      //  config_t inicial;
        if (command == "defmundo")
          if(atoi(arg.c_str()) <= 10 && atoi(arg.c_str()) > 0){
            m.criaMundo(atoi(arg.c_str()));
            cout << m.getLimites() <<endl;
          }
          else{
            PosiciCursor(5,9);
            cout << "Valor introduzido invalido ou muito alto. Prima uma tecla para tentar de novo";
            PosiciCursor(5,10);
            getchar();
          }
        else if (command == "defen")
            m.setEnergNinho(atoi(arg.c_str()));
        else if (command == "defpc")
            m.setEnergLim(atoi(arg.c_str()));
        else if (command == "defvt")
            m.setEnergTransf(atoi(arg.c_str()));
        else if (command == "defmi")
            if(atoi(arg.c_str()) <= 100 && atoi(arg.c_str()) >0)
              m.setPercentMig(atoi(arg.c_str()));
            else
              cout << "Valor introduzido muito alto";
        else if (command == "defme")
            m.setEnergMig(atoi(arg.c_str()));
        else if (command == "defnm")
            m.setMaxMig(atoi(arg.c_str()));
        else if (command == "executa"){
            leExecuta(comm_list,m,arg);
        }
        else if (command == "inicio"){ //descomentar para validar se os parâmetros foram todos inseridos
            //if(m.getLimites() != -1 && m.getEnergLim() != -1 && m.getEnergTransf() != -1 && m.getEnergNinho() != -1){ // mais tarde temos de adicionar aqui os comandos das migalhas
                LimpaEcra();
            ComandosSimul(m);//}

            //else{
                //PosiciCursor(5,8);
               // cout << "Ainda nao executou todas as configuracoes iniciais. Prima uma tecla para tentar de novo" << endl;
               // getchar();
            //}
        }
        else if (command == "ninho"){
              string arg1, arg2;
              istringstream iss(arg);
              iss >> (arg1); //linha
              getline(iss,arg2); //coluna
            if(atoi(arg1.c_str()) < m.getLimites() && atoi(arg2.c_str()) < m.getLimites() && atoi(arg1.c_str()) >= 0 && atoi(arg2.c_str()) >= 0)
                m.newNinho(atoi(arg1.c_str()), atoi(arg2.c_str()));
            else {
            cout << "Valores invalidos. Carregue numa tecla para continuar" << endl;
            getchar();
            }
        }
        else if (command == "criaf"){
              string arg1, arg2;
              istringstream iss(arg);
              iss >> (arg1); //quant
              getline(iss,arg2); //id ninho
            m.addFormigas(atoi(arg1.c_str()), atoi(arg2.c_str())); //  falta meter a imprimir
        }
        else if (command == "cria1"){
            string arg1, arg2,arg3;
              istringstream iss(arg);
              iss >> (arg1); //id ninho
              iss >> (arg2); //linha
              getline(iss,arg3); //coluna
            m.addFormigas(1,atoi(arg1.c_str()),atoi(arg2.c_str()),atoi(arg3.c_str())); // fazemos uso dos argumentos por default de c++

        }
        else if (command == "listamundo"){
            LimpaEcra();
            PosiciCursor(0,0);
            cout << m.getInfo();
            cout << "Prima uma tecla para voltar as opcoes";
            getchar();
        }
        else if (command == "listaninho"){
            LimpaEcra();
            PosiciCursor(0,0);
            cout << m.getNinho(atoi(arg.c_str())); // id do ninho
            cout << "Prima uma tecla para voltar as opcoes";
            getchar();
        }
        else if (command == "listaposicao"){
              string arg1, arg2;
              istringstream iss(arg);
              iss >> (arg1); //linha
              getline(iss,arg2); //coluna
            /*if(m.verificaPos(atoi(arg1.c_str()),atoi(arg2.c_str()))==false){
                Consola::clrscr();
                Consola::gotoxy(0,0);
                cout << m.getInfoCoord(atoi(arg1.c_str()), atoi(arg2.c_str()));
            }*/
            //else
            /*    cout << "Posicao esta vazia";
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "tempo"){
            PosiciCursor(5+m.getLimites()*4,7);
            cout << "Numero de iteracoes: ";
            PosiciCursor(5+m.getLimites()*4,8);
            getline(cin, arg1);
            m.iteracoes(atoi(arg1.c_str()));
          }*/
        }
      //  else if (command == )


}
        /* Executa os comandos em ficheiro de texto*/
int leExecuta(const vector<string>&comm_list,Mundo &m,const string nome){
          ifstream fs (nome);
          string comando, command;
          string params;

          if(fs.is_open()){

              while(getline(fs,comando)){ // temos de meter isto tudo numa linha mas sem os fscanf nao sei como se faz em c++
                    // getline para evitar problemas com buffers
              istringstream iss(comando);
              iss >> (command);
              getline (iss,params);
                if(check_command(command,comm_list)){ //verifica se o comando existe
                  if(command != "executa"){ // nao queremos entrar num loop infinito se estiver sempre a chamar "executa"
                    whichCommand(comm_list, command, params,m); // executa o comando lido
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

        /* Funções para simulação */
void ComandosSimul(Mundo &m){
  string comando, param, arg1,arg2,arg3,arg,command; //o parametro devera ser convertido para inteiro
  vector<string>comm_list;
  comm_list=load_commands("command_simul.txt");
  cout << "Iniciando simulacão " << endl;
  do{
     LimpaEcra();
     ImprimeMundo(m);
     listaComandos(comm_list);
     corTexto(Consola::CYAN_CLARO);
    PosiciCursor(5+m.getLimites()*4,5);
      cout << "[SIMUL]Insira comando.: para sair escreva 'sair'" << endl;
    PosiciCursor(5+m.getLimites()*4,6);
      getline(cin,comando);
        istringstream iss(comando);
        iss >> (command);
        getline(iss,param);
        arg = param;
    // getline para evitar problemas com buffers
      if (command == "sair"){
         cout << "[SIMUL] encerrando" << endl; return;
      }
      if (command == "executa"){
        leExecuta(comm_list,m,arg);
      }
    /* if(check_command(command,comm_list)==false){
         cout << "Comando invalido" << endl;
      }
      else {
        if (command == "executa"){
            leExecuta(comm_list,m,arg);
        }*/
       // if (command != "executa" && command != "inicio")
      // {

        whichCommand(comm_list, command, arg,m);
        //if (comando == "ninho"){
           /* do{
                PosiciCursor(5+m.getLimites()*4,7);
                cout << "Linha: " << endl;
                   PosiciCursor(5+m.getLimites()*4,8);
                getline(cin, arg1);
                    PosiciCursor(5+m.getLimites()*4,9);
                cout << "Coluna: " << endl;
                    PosiciCursor(5+m.getLimites()*4,10);
                getline(cin, arg2);
            }while(atoi(arg1.c_str()) >= m.getLimites() || atoi(arg2.c_str()) >= m.getLimites() || atoi(arg1.c_str()) < 0 || atoi(arg2.c_str()) < 0);
            m.newNinho(atoi(arg1.c_str()), atoi(arg2.c_str()));*/
        /*}
        else if (command == "criaf"){
            PosiciCursor(5+m.getLimites()*4,7);
            cout << "Numero de formigas: ";
            PosiciCursor(5+m.getLimites()*4,8);
            getline(cin, arg1);
            PosiciCursor(5+m.getLimites()*4,9);
            cout << "ID do ninho:";
            PosiciCursor(5+m.getLimites()*4,10);
            getline(cin, arg2);
            PosiciCursor(5+m.getLimites()*4,11);
            m.addFormigas(atoi(arg1.c_str()), atoi(arg2.c_str())); //  falta meter a imprimir
        }
        else if (command == "cria1"){
            PosiciCursor(5+m.getLimites()*4,7);
            cout << "ID do ninho:";
            PosiciCursor(5+m.getLimites()*4,8);
            getline(cin, arg1);
            do{
                PosiciCursor(5+m.getLimites()*4,9);
                cout << "Linha:";
                PosiciCursor(5+m.getLimites()*4,10);
                getline(cin, arg3);
                PosiciCursor(5+m.getLimites()*4,11);
                cout << "Coluna:";
                PosiciCursor(5+m.getLimites()*4,12);
                getline(cin, arg2);
            }while(atoi(arg2.c_str()) >= m.getLimites() || atoi(arg3.c_str()) >= m.getLimites() || atoi(arg2.c_str()) < 0 || atoi(arg3.c_str()) < 0);
            PosiciCursor(5+m.getLimites()*4,13);
            m.addFormigas(1,atoi(arg1.c_str()),atoi(arg2.c_str()),atoi(arg3.c_str())); // fazemos uso dos argumentos por default de c++

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
        else if (command == "listaposicao"){
            cout << "Linha:";
            getline(cin, arg1);
            cout << "\nColuna:";
            getline(cin, arg2);
            /*if(m.verificaPos(atoi(arg1.c_str()),atoi(arg2.c_str()))==false){
                Consola::clrscr();
                Consola::gotoxy(0,0);
                cout << m.getInfoCoord(atoi(arg1.c_str()), atoi(arg2.c_str()));
            }*/
            //else
            /*    cout << "Posicao esta vazia";
            cout << "Prima uma tecla para voltar as opcoes";
            Consola::getch();
        }
        else if (command == "tempo"){
            PosiciCursor(5+m.getLimites()*4,7);
            cout << "Numero de iteracoes: ";
            PosiciCursor(5+m.getLimites()*4,8);
            getline(cin, arg1);
            m.iteracoes(atoi(arg1.c_str()));
          }*/
   // }
     // }
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
            int linha, coluna;
            for(auto it=ninhos.begin(); it<ninhos.end(); it++){
                corTexto(Consola::AMARELO);
                linha =(*it)->getLinha();
                coluna =(*it)->getColuna();
                PosiciCursor(5 + coluna * 3, 5 + linha * 2);
                cout << (*it)->getAvatar();
                corTexto(Consola::VERMELHO);
                ImprimeFormigas((*it)->getFormigas());
            }


        }

void ImprimeFormigas (const vector <Ant*> &formigas){
            int linha, coluna;
            for(auto it=formigas.begin(); it<formigas.end(); it++){
                linha =(*it)->getLinha();
                coluna =(*it)->getColuna();
                PosiciCursor(5 + coluna * 3, 5 + linha * 2);
                cout << (*it)->getAvatar();
            }

        }


};

#endif // INTERFACE_H
