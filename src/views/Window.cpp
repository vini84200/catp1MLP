#include "Window.hpp"
#include "pessoa.hpp"

#include <gtkmm/application.h>
#include <iostream>
#include <string>

ApplicationWindow::ApplicationWindow(std::vector<Aluno>& alunos)
        : m_button("Cadastrar"), m_alunos(alunos), m_print_all_button("Imprimir todos")
{
    // Sets the border width of the window.
    set_border_width(10);


    add(m_grid);
    m_grid.set_border_width(10);

    m_grid.attach(m_nome_label, 0, 0);
    m_nome_label.set_text("Nome:");
    m_nome_label.show();

    m_grid.attach(m_nome_entry, 1, 0);
    m_nome_entry.show();

    m_grid.attach(m_dt_nasc_label, 0, 1);
    m_dt_nasc_label.set_text("Data de Nascimento:");
    m_dt_nasc_label.show();

    m_grid.attach(m_dt_nasc_entry, 1, 1);
    m_dt_nasc_entry.show();

    m_grid.attach(m_genero_label, 0, 2);
    m_genero_label.set_text("Genero:");
    m_genero_label.show();

    m_grid.attach(m_genero_entry, 1, 2);
    m_genero_entry.show();
    m_genero_entry.append(Pessoa::genero_str(Pessoa::GENERO::HOMEM_CIS), "Homem Cis");
    m_genero_entry.append(Pessoa::genero_str(Pessoa::GENERO::MULHER_CIS), "Mulher Cis");
    m_genero_entry.append(Pessoa::genero_str(Pessoa::GENERO::NAO_BINARIO), "Não Binário");
    m_genero_entry.append(Pessoa::genero_str(Pessoa::GENERO::TRANSGENERO), "Transgênero");

    m_nivel_label.set_text("Nível:");
    m_grid.attach(m_nivel_label, 0, 3);
    m_nivel_label.show();

    m_grid.attach(m_nivel_entry, 1, 3);
    m_nivel_entry.show();
    m_nivel_entry.append(Aluno::nivel_str(Aluno::NIVEL::GRADUACAO), "Graduação");
    m_nivel_entry.append(Aluno::nivel_str(Aluno::NIVEL::ESPECIALIZACAO), "Especialização");
    m_nivel_entry.append(Aluno::nivel_str(Aluno::NIVEL::MESTRADO), "Mestrado");
    m_nivel_entry.append(Aluno::nivel_str(Aluno::NIVEL::DOUTORADO), "Doutorado");

    m_grid.attach(m_matricula_label, 0, 4);
    m_matricula_label.set_text("Matrícula:");
    m_matricula_label.show();

    m_grid.attach(m_matricula_entry, 1, 4);
    m_matricula_entry.show();

    m_grid.attach(m_dt_matricula_label, 0, 5);
    m_dt_matricula_label.set_text("Data de Matrícula:");
    m_dt_matricula_label.show();

    m_grid.attach(m_dt_matricula_entry, 1, 5);
    m_dt_matricula_entry.show();



    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    m_button.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &ApplicationWindow::on_button_clicked));

    // This packs the button into the Window (a container).
    m_grid.attach(m_button, 0, 6, 2, 1);

    // The final step is to display this newly created widget...
    m_button.show();

    m_print_all_button.signal_clicked().connect([this](){
        std::cout << "Imprimindo todos os alunos" << std::endl;
        for (auto &aluno : m_alunos) {
            std::cout << "---" << std::endl;
            std::cout << aluno << std::endl;
        }
        std::cout << "---" << std::endl;
        std::cout << "Fim da lista de alunos" << std::endl;
    });

    m_grid.attach(m_print_all_button, 0, 7, 2, 1);
    m_print_all_button.show();


    show_all_children();

}

ApplicationWindow::~ApplicationWindow()
{
    std::cout << "Goodbye World" << std::endl;
}

void ApplicationWindow::on_button_clicked()
{
    std::cout << "Button was clicked" << std::endl;

    unsigned int dia, mes, ano;
    try {
        m_dt_nasc_entry.get_date(dia, mes, ano);
        DataHora dt_nasc(dia, mes, ano);
        m_dt_matricula_entry.get_date(dia, mes, ano);
        DataHora dt_matricula(dia, mes, ano);

        Aluno::NIVEL nivel = Aluno::nivel_enum(m_nivel_entry.get_active_id());
        Pessoa::GENERO genero = Pessoa::genero_enum(m_genero_entry.get_active_id());

        Aluno aluno(
                m_nome_entry.get_text(),
                dt_nasc,
                genero,
                nivel,
                m_matricula_entry.get_text(),
                dt_matricula);

        m_alunos.push_back(aluno);

        m_nome_entry.set_text("");
        m_dt_nasc_entry.clear_marks();
        m_genero_entry.set_active(0);
        m_nivel_entry.set_active(0);
        m_matricula_entry.set_text("");
        m_dt_matricula_entry.clear_marks();

        auto dialog =
                gtk_message_dialog_new(
                        this->gobj(),
                        GTK_DIALOG_DESTROY_WITH_PARENT,
                        GTK_MESSAGE_INFO,
                        GTK_BUTTONS_CLOSE,
                        "Aluno cadastrado com sucesso!");
        g_signal_connect_swapped(
                dialog,
                "response",
                G_CALLBACK(gtk_widget_destroy),
                dialog);

        gtk_dialog_run(GTK_DIALOG(dialog));

    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        auto dialog =
        gtk_message_dialog_new(
                this->gobj(),
                GTK_DIALOG_DESTROY_WITH_PARENT,
                GTK_MESSAGE_ERROR,
                GTK_BUTTONS_CLOSE,
                e.what());
        g_signal_connect_swapped(
                dialog,
                "response",
                G_CALLBACK(gtk_widget_destroy),
                dialog);

        gtk_dialog_run(GTK_DIALOG(dialog));
    }
}

