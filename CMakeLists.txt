cmake_minimum_required(VERSION 3.20)
project(CatpProjeto)

include_directories(.)

add_library(
    TheLib
    aluno.cpp 
    DataHora.cpp 
    pessoa.cpp 
)

add_executable(
    Alunos
    alunos.cpp 
)

target_link_libraries(
    Alunos PRIVATE TheLib
)