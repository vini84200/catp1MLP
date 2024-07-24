#include "pessoa.hpp"
#include "DataHora.hpp"
#include <regex>

std::string Pessoa::get_nome() const
{
  // faz cópia raza (verificar se é necessário construir uma cópia)
  return this->nome;
}

DataHora Pessoa::get_dt_nascimento() const
{
  // em princípio não tem problema em fazer cópia rasa (pois é um struct com literais)
  return this->dt_nascimento;
}

Pessoa::GENERO Pessoa::get_genero() const
{
  return this->genero;
}

void Pessoa::set_nome(const std::string nome)
{
  std::regex regex("(([A-Z])[a-z]+) (([A-Z])[a-z]+)");

  if (std::regex_match(nome, regex))
  {
    this->nome = nome;
  }
  else 
  {
    throw std::invalid_argument("Nome inválido");
  }
}

void Pessoa::set_dt_nascimento(const DataHora dt_nascimento)
{
  if (!dt_nascimento.isFuture())
    this->dt_nascimento = dt_nascimento;
  else {
    throw std::invalid_argument("Data de nascimento futura");
  }
}

void Pessoa::set_genero(const GENERO genero)
{
  this->genero = genero;
}

Pessoa::Pessoa(std::string nome, DataHora dt_nascimento, GENERO genero)
{
  this->set_nome(nome);
  this->set_dt_nascimento(dt_nascimento);
  this->set_genero(genero);
  std::cout << "> [Pessoa] Construtor chamado." << std::endl;
}

Pessoa::Pessoa(const Pessoa &outra)
{
  std::cout << "> [Pessoa] Construtor de Cópia chamado." << std::endl;

  this->set_dt_nascimento(outra.dt_nascimento);
  this->set_genero(outra.genero);
  this->set_nome(outra.nome);
}

Pessoa &Pessoa::operator=(const Pessoa &outra)
{
  std::cout << "> [Pessoa] operator= chamado." << std::endl;

  if (this != &outra)
  {
    this->set_dt_nascimento(outra.dt_nascimento);
    this->set_genero(outra.genero);
    this->set_nome(outra.nome);
  }

  return *this;
}

// sobrecarga do operator<< para atuar com Pessoa::Genero
std::ostream &operator<<(std::ostream &os, const Pessoa::GENERO g)
{
  switch (g)
  {
  case Pessoa::INDEFINIDO:
    os << "INDEFINIDO";
    break;
  case Pessoa::HOMEM_CIS:
    os << "HOMEM_CIS";
    break;
  case Pessoa::MULHER_CIS:
    os << "MULHER_CIS";
    break;
  case Pessoa::NAO_BINARIO:
    os << "NAO_BINARIO";
    break;
  case Pessoa::TRANSGENERO:
    os << "TRANSGENERO";
    break;
  default:
    os.setstate(std::ios_base::failbit);
  }
  return os;
}

// sobrecarga do operator<< para aceitar Pessoas
std::ostream &operator<<(std::ostream &os, const Pessoa &p)
{
  DataHora data = p.get_dt_nascimento();

  os << "Pessoa (Nome: " << p.get_nome(); // temos que usar os getters (pois os atributos agora são privados)
  os << ", Genero: " << p.get_genero();
  os << ", Nascimento: " << data;
  os << ")";
  return os;
}
