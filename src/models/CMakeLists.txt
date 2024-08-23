add_library(
    PessoasModels
        STATIC
    aluno.cpp
    DataHora.cpp
    pessoa.cpp
    funcionario.cpp
)

target_include_directories(
    PessoasModels
    PUBLIC .
)