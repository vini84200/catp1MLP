#include <iostream>

#include "aluno.hpp"
#include <regex>

Aluno::Aluno(std::string nome, DataHora dt_nascimento, GENERO genero, NIVEL nivel, std::string matricula, DataHora dt_matricula)
    : Pessoa(nome, dt_nascimento, genero)
{
  this->set_nivel(nivel);
  this->set_matricula(matricula);
  std::cout << "> [Aluno] Construtor chamado." << std::endl;
}

void Aluno::set_nivel(NIVEL nivel)
{
  this->nivel = nivel;
}

void Aluno::set_matricula(std::string matricula)
{
  std::regex matricula_regex("([0-9]{8})$");
  if (std::regex_match(matricula, matricula_regex))
  {
    this->matricula = matricula;
  }
  else
  {
    throw std::invalid_argument("Matrícula inválida");
  }
}

void Aluno::set_dt_matricula(DataHora _dt_matricula)
{
  if (_dt_matricula.isFuture())
    throw std::invalid_argument("Data de matrícula futura");
  if (_dt_matricula.isBefore(this->dt_nascimento))
    throw std::invalid_argument("Data de matrícula antes da data de nascimento");

  this->dt_matricula = dt_matricula;
}

// sobrecarga do operator<< para aceitar Pessoas
std::ostream &operator<<(std::ostream &os, const Aluno &a)
{
  return a.print(os);
}

std::ostream &Aluno::print(std::ostream &os) const
{
  os << "Nome: " << this->nome << std::endl;
  os << "Data de nascimento: " << this->dt_nascimento << std::endl;
  os << "Gênero: " << this->genero << std::endl;
  os << "Nível: " << this->nivel << std::endl;
  os << "Matrícula: " << this->matricula << std::endl;
  os << "Data de matrícula: " << this->dt_matricula << std::endl;
  return os;
}

std::string Aluno::nivel_str(Aluno::NIVEL n) {
    switch (n) {
        case INDEFINIDO: return "INDEFINIDO";
        case GRADUACAO: return "GRADUACAO";
        case ESPECIALIZACAO: return "ESPECIALIZACAO";
        case MESTRADO: return "MESTRADO";
        case DOUTORADO: return "DOUTORADO";
    }
}

Aluno::NIVEL Aluno::nivel_enum(const std::string &s) {
    if (s == "INDEFINIDO") return INDEFINIDO;
    if (s == "GRADUACAO") return GRADUACAO;
    if (s == "ESPECIALIZACAO") return ESPECIALIZACAO;
    if (s == "MESTRADO") return MESTRADO;
    if (s == "DOUTORADO") return DOUTORADO;
    throw std::invalid_argument("Nível inválido");
}
