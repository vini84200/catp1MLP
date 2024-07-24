#include<string>
#include<iostream>

#include "aluno.hpp"

int main(void){
  Aluno* a1 = new Aluno();
  Pessoa* p1 = new Aluno();

  std::cout << *a1 << std::endl;
  std::cout << *p1 << std::endl;

  return 0;
}
