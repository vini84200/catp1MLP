
#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm.h>
#include "aluno.hpp"

class ApplicationWindow : public Gtk::Window
{

public:
    ApplicationWindow(std::vector<Aluno>& alunos);
    virtual ~ApplicationWindow();

protected:
    //Signal handlers:
    void on_button_clicked();

    //Member widgets:
    Gtk::Grid m_grid;
    Gtk::Button m_button;
    Gtk::Button m_print_all_button;
    Gtk::Label m_nome_label;
    Gtk::Entry m_nome_entry;
    Gtk::Label m_dt_nasc_label;
    Gtk::Calendar m_dt_nasc_entry;
    Gtk::Label m_genero_label;
    Gtk::ComboBoxText m_genero_entry;
    Gtk::Label m_nivel_label;
    Gtk::ComboBoxText m_nivel_entry;
    Gtk::Label m_matricula_label;
    Gtk::Entry m_matricula_entry;
    Gtk::Label m_dt_matricula_label;
    Gtk::Calendar m_dt_matricula_entry;

    std::vector<Aluno>& m_alunos;
};

#endif