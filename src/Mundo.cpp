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
    if(!verificaPos(linha,coluna))//se estiver livre é devolvido false
        ninhos.push_back(new Nest(energiaNinho, energiaLim, energiaTransf, linha, coluna, (Consola::AZUL)));
    else{
        cout << "Posicao ocupada. Carregue numa tecla para continuar" << endl;
        getchar();
    }
}

bool Mundo::verificaPos(int linha, int col){
    int ocupada;
    for(auto it=ninhos.begin(); it < ninhos.end(); it++){
        ocupada=0;
        for(auto ij=ninhos.begin();ij <ninhos.end(); ij++){
            if((*ij)->verificaPos(linha,col) == true) //false se estiver livre
                    ocupada = 1;
            if((*ij)->verificaPosFormigas(linha, col))
                    ocupada = 1;
        }
    }
    if (ocupada ==1)
        return true;
    return false;
}

void Mundo::addFormigas(int num, char tipo,int ID , int linha, int coluna){
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
                (*it)->addFormigas(num, posy, posx,limite, tipo);
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



string Mundo::getInfoCoord(int linha, int coluna){
  ostringstream os;
  for(auto it=ninhos.begin();it < ninhos.end() ; it++){
    if((*it)->getColuna() == coluna && (*it)->getLinha() == linha)
      return (*it)->getInfoGeral();
    else{
    }
  }

  return os.str();
}
/*
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

*/
void Mundo::MigalhasIniciais(int percInicial, int energiaInic){
  int nMigalhas = ((limite * limite)*percInicial);
  int linha, coluna;

  while(nMigalhas > 0){
    do{
      linha = uniform01(0,limite-1);
      coluna = uniform01(0,limite-1);
    }while(verificaPos(linha,coluna) || linha >=limite || coluna >=limite );
    migalhas.push_back(new Migalha(energiaInic, linha, coluna));
    nMigalhas--;
  }
}

void Mundo::SpawnMigalha(){
  int nMigalhas = uniform01(0,getMaxMigalhInst());
  int linha, coluna;

  while(nMigalhas > 0){
    do{
      linha = uniform01(0,(limite-1));
      coluna = uniform01(0,(limite-1));
    }while(verificaPos(linha,coluna) || linha >=limite || coluna >=limite );
    migalhas.push_back(new Migalha(energiaMigalh, linha, coluna));
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


void Mundo::iteracoes(int num){
 int posx,posy;
  do{
    SpawnMigalha();

   /* for(auto it=ninhos.begin(); it < ninhos.end(); it++){
      if((*it)->getEnergy() > (*it)->getEnergiaInicial() * getEnergiaLim()){
        (*it)->addFormigas(80,(*it)->getPosX(),(*it)->getPosY(),getLimites());
        (*it)->setEnergy(-80);
      }
*/
    /*  for(auto ot=(*it)->ants.begin();ot < (*it)->ants.end(); ot++){
        for(auto it2= (*ot)->regras.begin();it2 < (*ot)->regras.end();it2++){
          if((*it2)->condicao(*this,(*ot)->getRVisao(),(*ot)->getRmov())){
            (*it2)->acao(*this, (*ot)->getRVisao(), (*ot)->getRmov());
          }
        }
      } //E PRECISO FAZER ISTO COMO METODOS DOS NINHOS E DAS FORMIGAS !! */
    //}
      for(auto it=ninhos.begin(); it < ninhos.end(); it++){
            (*it)->andar(limite,*this);
            /*do{
                posx = uniform01(0,limite-1);
                posy = uniform01(0,limite-1);


                (*it)->addFormigas(num, posy, posx,limite);


            }while(verificaPos(posy,posx));*/

    }

    num--;
  }while(num > 0);
}

void Mundo::addEnergyNinhos(int energy, int ID){
  for(auto it=ninhos.begin();it < ninhos.end(); it++){
    if((*it)->getID() == ID){
      (*it)->setEnergyAtual(energy);
      break;
    }
  }
}

void Mundo::addMigalha(int linha,int col){
  if(!verificaPos(linha,col))//se estiver livre é devolvido false
          migalhas.push_back(new Migalha(energiaMigalh, linha, col));
    else{
        cout << "Posicao ocupada. Carregue numa tecla para continuar" << endl;
        getchar();
    }
}

void Mundo::inseticida(int id){
  for(auto it=ninhos.begin();it < ninhos.end(); it++){
    if((*it)->getID() == id){
      (*it)->apagaFormigas();
      delete(*it);
      ninhos.erase(it);
      return;
    }
  }
}

void Mundo::addEnergyFormigas(int linh, int col, int add){
  for(auto it=ninhos.begin();it<ninhos.end();it++){
    if((*it)->addEnergyFormigas(linh,col,add)) //se devolver true ja encontrou a formiga e sai do ciclo
      break;
  }
}

void Mundo::mataFormigas(int linh,int col){
  for(auto it=ninhos.begin();it<ninhos.end();it++){
    if((*it)->mataFormigas(linh, col))
      break;
  }
}
