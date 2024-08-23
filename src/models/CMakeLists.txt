add_library(
    PessoasModels
        STATIC
    aluno.cpp
    DataHora.cpp
    pessoa.cpp
    funcionario.cpp
        map_init.cpp
        map_init.h
)

target_include_directories(
    PessoasModels
    PUBLIC .
)