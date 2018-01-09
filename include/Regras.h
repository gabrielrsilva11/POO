#ifndef REGRAS_H
#define REGRAS_H

class Mundo;

class Regras{
public:
    Regras(){};
  virtual bool condicao(Mundo* a)=0;
  virtual void acao(Mundo* a)=0;

  virtual ~Regras(){};
};

class RegraFoge:public Regras{
public:
   virtual bool condicao(Mundo* a) {return true;};
   virtual void acao(Mundo* a){return;};

   virtual ~RegraFoge(){};
};

class RegraPersegue:public Regras{
public:
  virtual bool condicao(Mundo* a){};
  virtual void acao(Mundo* a){};
  virtual ~RegraPersegue(){};
};

class RegraAssalta:public Regras{
public:
  virtual bool condicao(Mundo* a){};
  virtual void acao(Mundo* a){};
  virtual ~RegraAssalta(){};
};

class RegraProtege:public Regras{
public:
  virtual bool condicao(Mundo* a){};
  virtual void acao(Mundo* a){};
  virtual ~RegraProtege(){};
};

class RegraProcuraMigalha:public Regras{
public:
  virtual bool condicao(Mundo* a){};
  virtual void acao(Mundo* a){};
  virtual ~RegraProcuraMigalha(){};
};

class RegraComeMigalha:public Regras{
public:
  virtual bool condicao(Mundo* a){};
  virtual void acao(Mundo* a){};
  virtual ~RegraComeMigalha(){};
};

class RegraVaiParaNinho:public Regras{
public:
  virtual bool condicao(Mundo* a){};
  virtual void acao(Mundo* a){};
  virtual ~RegraVaiParaNinho(){}
};

class RegraPasseia:public Regras{
public:
  virtual bool condicao(Mundo* a){return true;}
  virtual void acao(Mundo* a){};
  virtual ~RegraPasseia(){};
};

#endif // REGRAS_H
