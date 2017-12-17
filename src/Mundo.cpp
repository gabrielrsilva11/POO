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
  setMapa(x,y);
  ninhos.push_back(new Nest(inicial.energiaNinho, inicial.energiaLim, inicial.energiaTransf, x, y, (Consola::AZUL)));
    Consola::gotoxy(x,y);
    cout << "O";
}

void Mundo::addFormigas(int num, int ID , int x, int y){
    int posx, posy;
    if(ninhos.empty()){
        cout << "Ainda nao existem ninhos com formigas";
        return;
    }
  for(auto it=ninhos.begin(); it < ninhos.end(); it++){
    if((*it)->getID() == ID){
        if(num == 1 && verificaPos(x,y) == false && x != -1 && y != -1){
            setMapa(x,y);
            (*it)->addFormigas(num, x, y);
            Consola::gotoxy(x,y);
            cout << "*";
        }
        else{
            for(int i=0; i < num; i++){
                    do{
                        posx = uniform01(0,8);
                        posy = uniform01(0,8);
                    }while(verificaPos(posx,posy)==false);
                    setMapa(posx,posy);
                    (*it)->addFormigas(num,posx,posy);
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
//            (*it)->andar();
            //(*it)->spawn() eventualmente fazer isto nao sei se isto funciona sequer.
        }
    }
}
