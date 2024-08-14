#include "pessoa.hpp"
#include "funcionario.hpp"
#include "aluno.hpp"
#include <vector>

int main() {
    std::vector<Pessoa*> pessoas;

    pessoas.push_back(new Aluno("Joao Paulo", time(0), Pessoa::GENERO::HOMEM_CIS, Aluno::GRADUACAO, "12345678", DataHora()));
    pessoas.push_back(new Funcionario("Maria Goncalo", time(0), Pessoa::GENERO::MULHER_CIS, DataHora(), Funcionario::GERENTE));
    pessoas.push_back(new Pessoa("Jorgim Silva", DataHora(), Pessoa::NAO_BINARIO));
    pessoas.push_back(new Aluno("Ana Souza", time(0), Pessoa::GENERO::MULHER_CIS, Aluno::GRADUACAO, "87654321", DataHora()));
    pessoas.push_back(new Funcionario("Pedro Santos", time(0), Pessoa::GENERO::HOMEM_CIS, DataHora(), Funcionario::ANALISTA));
    pessoas.push_back(new Pessoa("Mariana Oliveira", DataHora(), Pessoa::NAO_BINARIO));
    pessoas.push_back(new Aluno("Lucas Pereira", time(0), Pessoa::GENERO::HOMEM_CIS, Aluno::ESPECIALIZACAO, "98765432", DataHora()));
    pessoas.push_back(new Funcionario("Carla Rodrigues", time(0), Pessoa::GENERO::MULHER_CIS, DataHora(), Funcionario::ANALISTA));
    pessoas.push_back(new Pessoa("Rafaela Costa", DataHora(), Pessoa::NAO_BINARIO));
    pessoas.push_back(new Aluno("Gustavo Santos", time(0), Pessoa::GENERO::HOMEM_CIS, Aluno::GRADUACAO, "54321678", DataHora()));

    for (auto p : pessoas) {
        std::cout << *p << std::endl;
    }

}
