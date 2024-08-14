#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "DataHora.hpp"
#include "pessoa.hpp"

class Funcionario : public Pessoa {
    public:
    enum CARGO {
        ESTAGIARIO,
        PROGRAMADOR_JUNIOR,
        PROGRAMADOR_PLENO,
        ANALISTA,
        GERENTE,
    };

    Funcionario
    (
        std::string nome = "INDEFINIDO",
        DataHora nascimento = DataHora(),
        GENERO genero= Pessoa::INDEFINIDO,
        DataHora ingresso = DataHora(),
        CARGO cargo = ESTAGIARIO
    );

    std::ostream &print(std::ostream &) const override;

    void set_cargo(CARGO);
    void set_ingresso(DataHora);

    CARGO get_cargo() const;
    DataHora get_ingresso() const;


    private:
    CARGO cargo;
    DataHora ingresso;
};

std::ostream &operator<<(std::ostream &, const Funcionario::CARGO);
std::ostream &operator<<(std::ostream &, const Funcionario &);

#endif
