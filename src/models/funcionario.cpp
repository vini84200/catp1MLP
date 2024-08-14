#include "funcionario.hpp"

Funcionario::Funcionario(std::string nome, DataHora nascimento, GENERO genero, DataHora ingresso, CARGO cargo)
    : Pessoa(nome, nascimento, genero)
{
    set_cargo(cargo);
    set_ingresso(ingresso);
}

void Funcionario::set_cargo(CARGO n_cargo)
{
    cargo = n_cargo;
}

void Funcionario::set_ingresso(DataHora n_ingresso)
{
    if (n_ingresso.isBetween(dt_nascimento, DataHora()))
    {
        ingresso = n_ingresso;
    }
    else
    {
        std::cerr << "Data de ingresso inválida" << std::endl;
    }
}

Funcionario::CARGO Funcionario::get_cargo() const
{
    return cargo;
}

DataHora Funcionario::get_ingresso() const
{
    return ingresso;
}

std::ostream &Funcionario::print(std::ostream &os) const
{
    return os << "Nome: " << this->nome << std::endl
              << "Data de nascimento: " << this->dt_nascimento << std::endl
              << "Gênero: " << this->genero << std::endl
              << "Cargo: " << this->cargo << std::endl
              << "Data de Ingresso: " << this->ingresso << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Funcionario::CARGO cargo)
{
    switch (cargo)
    {
    case Funcionario::ESTAGIARIO:
        return os << "Estagiário";
    case Funcionario::PROGRAMADOR_JUNIOR:
        return os << "Programador Júnior";
    case Funcionario::PROGRAMADOR_PLENO:
        return os << "Programador Pleno";
    case Funcionario::ANALISTA:
        return os << "Analista";
    case Funcionario::GERENTE:
        return os << "Gerente";
    default:
        throw std::invalid_argument("Cargo inválido");
    }
}

std::ostream &operator<<(std::ostream &os, const Funcionario &f)
{
    return f.print(os);
}
