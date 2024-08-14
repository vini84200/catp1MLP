add_library(
    PessoasModels
    aluno.cpp
    DataHora.cpp
    pessoa.cpp
    funcionario.cpp
)

target_include_directories(
    PessoasModels
    PUBLIC .
)