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
void Mundo::newNinho(config_t inicial, int x, int y){
  if(mapa[x][y]==1){
    cout << "Posicao ocupada" << endl;
    return;
  }
  ninhos.push_back(new Nest(inicial.energiaNinho, inicial.energiaLim, inicial.energiaTransf, x, y, (Consola::AZUL)));
  /*
  PARA IMPRIMIR O NINHO NESTA POSICAO
  gotoxy(x, y);
  cout << Nest::getAvatar();*/
}

void Mundo::addFormigas(int num, int ID , int x, int y){
  for(auto it=ninhos.begin(); it < ninhos.end(); it++){
    if((*it)->getID() == ID){
      addFormigas(num, x, y);
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
            for(auto it2=(*it)->ants.begin();(*it2)<(*it)->ants.end();it2++){ // ou fazer uma função que retorne o vetor das formigas
                (*it2)->move();
            }
            //(*it)->spawn() eventualmente fazer isto nao sei se isto funciona sequer.
        }
    }
}
