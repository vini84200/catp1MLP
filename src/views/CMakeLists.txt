find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_library(
    Views 
    Window.cpp
)

target_include_directories(
    Views
    PUBLIC .
    ${GTK3_INCLUDE_DIRS}
    ${GTKMM_INCLUDE_DIRS}
)

target_link_libraries(
    Views PRIVATE PessoasModels
    ${GTK3_LIBRARIES}
    ${GTKMM_LIBRARIES}
)