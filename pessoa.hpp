#include <string>
#include <iostream>
#include "DataHora.hpp"

class Pessoa
{
public:
   enum GENERO
   {
      INDEFINIDO,
      HOMEM_CIS,
      MULHER_CIS,
      NAO_BINARIO,
      TRANSGENERO
   };

   Pessoa(std::string = "INDEFINIDO", DataHora = DataHora(), GENERO = INDEFINIDO); // construtor com valores-default
   Pessoa(const Pessoa &);                                                         // construtor de cópia

   // sobrecarga de atribuição
   virtual Pessoa &operator=(const Pessoa &);

   // getters:
   std::string get_nome() const;
   DataHora get_dt_nascimento() const;
   GENERO get_genero() const;

   // setters:
   void set_nome(const std::string);
   void set_dt_nascimento(const DataHora);
   void set_genero(const GENERO);

protected:
   std::string nome;
   DataHora dt_nascimento;
   GENERO genero;
};

// sobrecarga do operator<< para atuar com Pessoa::Genero
std::ostream &operator<<(std::ostream &, const Pessoa::GENERO);
std::ostream &operator<<(std::ostream &, const Pessoa &);
