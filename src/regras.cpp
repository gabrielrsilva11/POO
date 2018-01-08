#include "Regras.h"

int RegraFoge::condicao(Mundo* a){
  vector <Nest*> v = a.getNinhos();

  for(auto it=v.begin(); it < v.end();it++){
      vector <Ant*> a = (*it)->getFormigas();
      for(auto ot=a.begin();ot < a.end();ot++){
        for(int i=1;i<getRvisao();i++){
          if(getPosX()+i == (*ot)->getPosX() && getComunidade() != (*ot)->getComunidade())
            return 1;
          else if(getPosX()-i == (*ot)->getPosX() && getComunidade() != (*ot)->getComunidade())
            return 2;
          else if(getPosY()+i == (*ot)->getPosY() && getComunidade() != (*ot)->getComunidade())
            return 3;
          else if(getPosY()+i == (*ot)->getPosY() && getComunidade() != (*ot)->getComunidade())
            return 4;
        }
      }
  }
}
