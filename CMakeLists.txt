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
    Alunos PUBLIC PessoasModels
)

add_executable(
    ListaPessoas
    exemple/lista_pessoas.cpp
)

target_link_libraries(
    ListaPessoas PRIVATE PessoasModels
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)


add_executable( CadastroAlunos
    src/app.cpp
    src/views/Window.cpp
)

include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set_property(TARGET CadastroAlunos PROPERTY CXX_STANDARD 17)


message(STATUS "GTK3_INCLUDE_DIRS: ${GTK3_INCLUDE_DIRS}")
message(STATUS "GTK3_LIBRARIES: ${GTK3_LIBRARIES}")
message(STATUS "GTKMM_INCLUDE_DIRS: ${GTKMM_INCLUDE_DIRS}")
message(STATUS "GTKMM_LIBRARIES: ${GTKMM_LIBRARIES}")

target_link_libraries(
    CadastroAlunos PUBLIC PessoasModels
#        ${GTK3_LIBRARIES}
        ${GTKMM_LIBRARIES}
)
