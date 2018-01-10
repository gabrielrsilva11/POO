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
void Mundo::newNinho( int x, int y){
  if(mapa[x][y]==1){
    cout << "Posicao ocupada" << endl;
    return;
  }
  setMapa(x,y);
  ninhos.push_back(new Nest(energiaNinho, energiaLim, energiaTransf, x, y, (Consola::AZUL)));
    Consola::gotoxy(x,y);
    cout << "O";
}

void Mundo::addFormigas(int num, int ID , int x, int y){
    int posx=x, posy=y;
    if(ninhos.empty()){
        cout << "Ainda nao existem ninhos";
        return;
    }
  for(auto it=ninhos.begin(); it < ninhos.end(); it++){
    if((*it)->getID() == ID){
        if(num == 1 && (verificaPos(x,y) == false)){
            if(posx != -1 && posy != -1){
                posx=uniform01(0,8);
                posy=uniform01(0,8);
            }
            setMapa(posx,posy);
            (*it)->addFormigas(num, posx, posy,limite);
        }
        else{
            for(int i=0; i < num; i++){
                    do{
                        posx = uniform01(0,8);
                        posy = uniform01(0,8);
                    }while(verificaPos(posx,posy)==false);
                    setMapa(posx,posy);
                    (*it)->addFormigas(num,posx,posy,limite);
            }
        }
      return;
    }
  }
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

bool Mundo::verificaPos(int x, int y){
  if(mapa[x][y] == 1)
    return false;
  else
    return true;
}

string Mundo::getInfoCoord(int x, int y){
  ostringstream os;
  for(auto it=ninhos.begin();it < ninhos.end() ; it++){
    if((*it)->getPosX() == x && (*it)->getPosY() == y)
      return (*it)->getInfoGeral();
    else{

    }
  }

  return os.str();
}

void Mundo::avancar(int num){
    for(int i=0;i<num;i++){
        for(auto it=ninhos.begin();it<ninhos.end();it++){ // vamos ter de chamar o espirito do natal para nos ajudar com isto
            (*it)->andar();
            //(*it)->spawn() eventualmente fazer isto nao sei se isto funciona sequer.
        }
    }
}

void Mundo::MigalhasIniciais(int percInicial, int energiaInic){
  int nMigalhas = ((limite * limite)*percInicial);
  int posX, posY;

  while(nMigalhas != 0){
    do{
      posx = uniform01(0,getLimites());
      posy = uniform01(0,getLimites());
    }while(verificaPos(posx,posy)==false);
    migalhas.push_back(new Migalha(energiaInic, posx, posy));
    setMapa(posx,posy);
    nMigalhas--;
  }
}

void Mundo::SpawnMigalha(){
  int nMigalhas = uniform01(0,getMaxMigalhInst());

  while(nMigalhas != 0){
    do{
      posx = uniform01(0,getLimites());
      posy = uniform01(0,getLimites());
    }while(verificaPos(posx,posy)==false);
    migalhas.push_back(new Migalha(energiaInic, posx, posy));
    setMapa(posx,posy);
    nMigalhas--;
  }
}

Migalha* Mundo::getMigalhaElemento(int i){
  return migalhas[i];
}

void Mundo::apagaMigalha(int i){
  migalhas.erase(migalhas.begin()+i);
}

void Mundo::removeMigalhas(){
  for(int i = 0; i < getMigalhasSize(); i++){
    if(getMigalhaElemento(i) -> checkDestroy()== true){
      removeMapa(getMigalhaElemento(i)->getPosX(), getMigalhaElemento(i)->getPosY())
      apagaMigalha(i);
    }
  }
}

void Mundo::Iteracoes(int num){

  do{
    SpawnMigalha();

    for(auto it=ninhos.begin(); it < ninhos.end(); it++){
      if((*it)->getEnergy() > (*it)->getEnergyInicial() * getEnergiaLim()){
        (*it)->addFormigas(80,(*it)->getPosX(),(*it)->getPosY(),getLimites());
        (*it)->setEnergy(-80);
      }
      /*
      for(auto ot=(*it)->ants.begin();ot < (*it)->ants.end(); ot++){
        for(auto it2= (*ot)->regras.begin();it2 < (*ot)->regras.end();it2++){
          if((*it2)->condicao(*this,(*ot)->getRVisao(),(*ot)->getRmov())){
            (*it2)->acao(*this, (*ot)->getRVisao(), (*ot)->getRmov());
          }
        }
      } E PRECISO FAZER ISTO COMO METODOS DOS NINHOS E DAS FORMIGAS !! */
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

void Mundo::addMigalha(int col, linha){
  // codigo de verificacao das posicoes que esta na funcao de andar.
  migalhas.push_back(new Migalha(energiaInic, posx, posy));
}

void Mundo::Inseticida(int id){
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
