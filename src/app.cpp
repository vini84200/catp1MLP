#include "views/Window.hpp"
#include "aluno.hpp"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.vjf.cadastro_alunos");

    std::vector<Aluno> alunos;

    ApplicationWindow helloworld(alunos);

    //Shows the window and returns when it is closed.
    return app->run(helloworld);
}
