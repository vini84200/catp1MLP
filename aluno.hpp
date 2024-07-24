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

  Aluno(std::string = "INDEFINIDO", time_t = time(0), GENERO = Pessoa::INDEFINIDO, NIVEL = INDEFINIDO, std::string = "INDEFINIDO");

  void set_nivel(NIVEL);
  void set_matricula(std::string);

private:
  NIVEL nivel;
  std::string matricula;
};

// sobrecarga do operator<<
std::ostream &operator<<(std::ostream &, const Aluno &);
