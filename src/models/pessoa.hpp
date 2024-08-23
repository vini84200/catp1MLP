#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <string>
#include <iostream>
#include <map>
#include "map_init.h"
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
    static std::map<GENERO, std::string> get_genero_map() {
        return {
            {INDEFINIDO, "INDEFINIDO"},
            {HOMEM_CIS, "HOMEM_CIS"},
            {MULHER_CIS, "MULHER_CIS"},
            {NAO_BINARIO, "NAO_BINARIO"},
            {TRANSGENERO, "TRANSGENERO"}
        };
    }
    static std::map<std::string, GENERO> get_inv_genero_map() {
        return {
            {"INDEFINIDO", INDEFINIDO},
            {"HOMEM_CIS", HOMEM_CIS},
            {"MULHER_CIS", MULHER_CIS},
            {"NAO_BINARIO", NAO_BINARIO},
            {"TRANSGENERO", TRANSGENERO}

        };
    }
    static const std::string genero_str(GENERO g) { return get_genero_map()[g]; }
    static const GENERO genero_enum(const std::string &s) { return get_inv_genero_map()[s]; }

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

   virtual std::ostream &print(std::ostream &) const;

protected:
   std::string nome;
   DataHora dt_nascimento;
   GENERO genero;
};

// sobrecarga do operator<< para atuar com Pessoa::Genero
std::ostream &operator<<(std::ostream &, const Pessoa::GENERO);
std::ostream &operator<<(std::ostream &, const Pessoa &);


#endif