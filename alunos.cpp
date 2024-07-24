#include <string>
#include <iostream>

#include "aluno.hpp"

int main(void)
{
  Aluno *a1 = new Aluno();
  Pessoa *p1 = new Aluno("Joao Pedro");

  std::cout << *a1 << std::endl;
  std::cout << *p1 << std::endl;

  Pessoa p;
  p.set_nome("Primeiro Teste");
  std::cout << "p antes: " << p << std::endl;
  Pessoa p2 = p;
  p.set_nome("Teste Dois");
  std::cout << "p depois: " << p << std::endl;
  std::cout << "p2: " << p2 << std::endl;

  Pessoa p3;
  p3 = p;
  p.set_nome("Teste Final");

  std::cout << "p final: " << p << std::endl;
  std::cout << "p2: " << p2 << std::endl;
  std::cout << "p3: " << p3 << std::endl;

  return 0;
}
