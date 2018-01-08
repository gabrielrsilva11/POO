#ifndef REGRAS_H
#define REGRAS_H

#include "includeme.h"

class Regra{
public:
  virtual int condicao()=0;
  virtual void acao()=0;
};

class RegraFoge:public Regras{
public:
  virtual bool condicao(Mundo* a);
  virtual void acao(Mundo* a);
};

class RegraPersegue:public Regras{
public:
  virtual bool condicao(Mundo* a);
  virtual void acao(Mundo* a);
};

class RegraAssalta:public Regras{
public:
  virtual bool condicao(Mundo* a);
  virtual void acao(Mundo* a);
};

class RegraProtege:public Regras{
public:
  virtual bool condicao(Mundo* a);
  virtual void acao(Mundo* a);
};

class RegraProcuraMigalha:public Regras{
public:
  virtual bool condicao(Mundo* a);
  virtual void acao(Mundo* a);
};

class RegraComeMigalha:public Regras{
public:
  virtual bool condicao(Mundo* a);
  virtual void acao(Mundo* a);
};

class RegraVaiParaNinho:public Regras{
public:
  virtual bool condicao(Mundo* a);
  virtual void acao(Mundo* a);
};

class RegraPasseia:public Regras{
public:
  virtual bool condicao(Mundo* a){return true};
  virtual void acao(Mundo* a);
};

#endif
