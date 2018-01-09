#include "Mundo.h"

/*
Mundo::Mundo()
{
    //ctor
}

Mundo::~Mundo()
{
    //dtor
}
*/
void Mundo::newNinho( int linha, int coluna){
  ninhos.push_back(new Nest(energiaNinho, energiaLim, energiaTransf, linha, coluna, (Consola::AZUL)));
}

void Mundo::addFormigas(int num, int ID , int linha, int coluna){
    int posx=coluna, posy=linha,i;
    int adicionadas=0, ocupada = 0;
    if(ninhos.empty()){
        cout << "Ainda nao existem ninhos. Prima uma tecla para continuar";
        getchar();
        return;
    }


  for(auto it=ninhos.begin(); it < ninhos.end(); it++){
    if((*it)->getID() == ID){
        do{
            ocupada = 0;
            posx = uniform01(0,limite-1);
            posy = uniform01(0,limite-1);
            for(auto ij=ninhos.begin();ij <ninhos.end(); ij++){
                //cout << posx << posy << endl;
                if((*ij)->verificaPos(posy,posx) == true) //false se estiver livre
                    ocupada = 1;
                if((*ij)->verificaPosFormigas(posy, posx))
                    ocupada = 1;
            }
            if(ocupada == 0){
                (*it)->addFormigas(num, posy, posx,limite);
                adicionadas++;
            }
        }while(adicionadas < num);
    }
  }
   return;
}

string Mundo::getInfo() const{
  ostringstream os;
  for(auto it=ninhos.begin(); it < ninhos.end(); it++){
    os << (*it)->getInfoGeral();
  }
  // vai faltar implementar a parte das migalhas para o final
  return os.str();
}

string Mundo::getNinho(int ID) const{
  for(auto it=ninhos.begin(); it<ninhos.end(); it++){
    if(ID == (*it)->getID()){
      return (*it)->getInfoGeral();
    }
  }
  return "O ninho com este ID nao existe";
}

string Mundo::getInfoAntsNinho(int ID) const{
  for(auto it=ninhos.begin(); it<ninhos.end(); it++){
    if(ID == (*it)->getID()){
      return (*it)->getAntsInfo();
    }
  }
  return "O ninho com este ID nao existe";
}



string Mundo::getInfoCoord(int x, int y){
  ostringstream os;
  for(auto it=ninhos.begin();it < ninhos.end() ; it++){
    if((*it)->getColuna() == x && (*it)->getLinha() == y)
      return (*it)->getInfoGeral();
    else{

    }
  }

  return os.str();
}

void Mundo::iteracoes(int num=1){
        int ocupada, posx, posy;
            while(1){
            ocupada = 0;
            posx = uniform01(0,limite-1);
            posy = uniform01(0,limite-1);

            for(auto ij=ninhos.begin();ij <ninhos.end(); ij++){
                cout << posx << posy << endl;
                if((*ij)->verificaPos(posy,posx) == true) //false se estiver livre
                    ocupada = 1;
                if((*ij)->verificaPosFormigas(posy, posx))
                    ocupada = 1;
            }
            }

    for(int i=0;i<num;i++){
        for(auto it=ninhos.begin();it<ninhos.end();it++){ // vamos ter de chamar o espirito do natal para nos ajudar com isto
            (*it)->andar(limite);
            //(*it)->spawn() eventualmente fazer isto nao sei se isto funciona sequer.
        }
    }
}


void Mundo::MigalhasIniciais(int percInicial, int energiaInic){
  int nMigalhas = ((limite * limite)*percInicial);
  int posX, posY;

  while(nMigalhas != 0){
   /* do{
      posX = uniform01(0,getLimites());
      posY = uniform01(0,getLimites());
    }while(verificaPos(posX,posY)==false);*/
    migalhas.push_back(new Migalha(energiaInic, posX, posY));
    nMigalhas--;
  }
}

void Mundo::SpawnMigalha(){
  int nMigalhas = uniform01(0,getMaxMigalhInst()), posx,posy;

  while(nMigalhas != 0){
   /* do{
      posx = uniform01(0,getLimites());
      posy = uniform01(0,getLimites());
    }while(verificaPos(posx,posy)==false);*/
    migalhas.push_back(new Migalha(energiaMigalh, posx, posy));
    nMigalhas--;
  }
}

Migalha* Mundo::getMigalhaElemento(int i){
  return migalhas[i];
}

void Mundo::apagaMigalha(int i){
  migalhas.erase(migalhas.begin()+i);
}

void Mundo::removeMigalha(){
  for(int i = 0; i < getMigalhasSize(); i++){
    if(getMigalhaElemento(i) -> checkDestroy()== true){
      apagaMigalha(i);
    }
  }
}
