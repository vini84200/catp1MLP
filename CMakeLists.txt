cmake_minimum_required(VERSION 3.20)
project(CatpProjeto)

add_subdirectory(
    src/models
)

add_executable(
    Alunos
    exemple/alunos.cpp 
)

target_link_libraries(
    Alunos PRIVATE PessoasModels
)

add_executable(
    ListaPessoas
    exemple/lista_pessoas.cpp
)

target_link_libraries(
    ListaPessoas PRIVATE PessoasModels
)

add_subdirectory(
    src/views
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)


add_executable( CadastroAlunos
    src/app.cpp
)

include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

target_link_libraries(
    CadastroAlunos PRIVATE Views PessoasModels
    ${GTK3_LIBRARIES}
    ${GTKMM_LIBRARIES}
)
