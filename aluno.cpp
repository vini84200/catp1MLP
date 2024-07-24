#include<iostream>

#include "aluno.hpp"

Aluno::Aluno(std::string nome, time_t dt_nascimento, GENERO genero, NIVEL nivel, std::string matricula){
  this->set_nome(nome);
  this->set_dt_nascimento(dt_nascimento);
  this->set_genero(genero);
  this->set_nivel(nivel);
  this->set_matricula(matricula);
  std::cout << "> [Aluno] Construtor chamado." << std::endl;
}

void Aluno::set_nivel(NIVEL nivel){
  this->nivel = nivel;
}

void Aluno::set_matricula(std::string matricula){
  this->matricula = matricula;
}

// sobrecarga do operator<< para aceitar Pessoas
std::ostream& operator<<(std::ostream& os, const Aluno& a){
  os << "Aluno (";
  os << (Pessoa&)a;
  os << ")";
  return os;
}
