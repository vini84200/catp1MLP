#include"pessoa.hpp"

std::string Pessoa::get_nome() const{
  // faz cópia raza (verificar se é necessário construir uma cópia)
  return this->nome;
}

time_t Pessoa::get_dt_nascimento() const{
  // em princípio não tem problema em fazer cópia rasa (pois é um struct com literais)
  return this->dt_nascimento;
}

Pessoa::GENERO Pessoa::get_genero() const{
  return this->genero;
}

void Pessoa::set_nome(const std::string nome){
  this->nome = nome;
}

void Pessoa::set_dt_nascimento(const time_t dt_nascimento){
  this->dt_nascimento = dt_nascimento;
}

void Pessoa::set_genero(const GENERO genero){
  this->genero = genero;
}

Pessoa::Pessoa(std::string nome, time_t dt_nascimento, GENERO genero){
  this->set_nome(nome);
  this->set_dt_nascimento(dt_nascimento);
  this->set_genero(genero);
  std::cout << "> [Pessoa] Construtor chamado." << std::endl;
}

Pessoa::Pessoa(const Pessoa& outra){
  std::cout << "> [Pessoa] Construtor de Cópia chamado." << std::endl;

  this->set_dt_nascimento(outra.dt_nascimento);
  this->set_genero(outra.genero);
  this->set_nome(outra.nome);
}

Pessoa& Pessoa::operator=(const Pessoa& outra){
  std::cout << "> [Pessoa] operator= chamado." << std::endl;

  if(this != &outra){
     this->set_dt_nascimento(outra.dt_nascimento);
     this->set_genero(outra.genero);
    this->set_nome(outra.nome);
  }

  return *this;
}

// sobrecarga do operator<< para atuar com Pessoa::Genero
std::ostream& operator<<(std::ostream& os, const Pessoa::GENERO g){
  switch(g){
     case Pessoa::INDEFINIDO  : os << "INDEFINIDO"; break;
     case Pessoa::HOMEM_CIS   : os << "HOMEM_CIS"; break;
     case Pessoa::MULHER_CIS  : os << "MULHER_CIS"; break;
     case Pessoa::NAO_BINARIO : os << "NAO_BINARIO"; break;
     case Pessoa::TRANSGENERO : os << "TRANSGENERO"; break;
     default                  : os.setstate(std::ios_base::failbit);
  }
  return os;
}

// sobrecarga do operator<< para aceitar Pessoas
std::ostream& operator<<(std::ostream& os, const Pessoa& p){
  time_t data = p.get_dt_nascimento();
  tm *ltm = localtime(&data);

  os << "Pessoa (Nome: " << p.get_nome();   // temos que usar os getters (pois os atributos agora são privados)
  os << ", Genero: " << p.get_genero() ;
  os << ", Nascimento: " << ltm->tm_mday << "/" << 1+ltm->tm_mon << "/" << 1900+ltm->tm_year;
  os << ")";
  return os;
}
