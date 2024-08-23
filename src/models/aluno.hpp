#ifndef ALUNOS_HPP
#define ALUNOS_HPP
#include <iostream>

#include "pessoa.hpp"

// define uma classe filha de Pessoa (tendo acesso publico a ela)
class Aluno : public Pessoa
{
public:
  enum NIVEL
  {
    INDEFINIDO,
    GRADUACAO,
    ESPECIALIZACAO,
    MESTRADO,
    DOUTORADO
  };

  static std::string nivel_str(NIVEL n);
  static NIVEL nivel_enum(const std::string &s);


  Aluno(std::string = "INDEFINIDO", DataHora nasc= DataHora(), GENERO = Pessoa::INDEFINIDO, NIVEL = INDEFINIDO, std::string = "00000000", DataHora dt_matricula= DataHora());

  void set_nivel(NIVEL);
  void set_matricula(std::string);
  void set_dt_matricula(DataHora);

  std::ostream &print(std::ostream &) const override;




private:
  NIVEL nivel;
  std::string matricula;
  DataHora dt_matricula;
};

// sobrecarga do operator<<
std::ostream &operator<<(std::ostream &, const Aluno &);

#endif