
#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm.h>

class HelloWorld : public Gtk::Window
{

public:
    HelloWorld();
    virtual ~HelloWorld();

protected:
    //Signal handlers:
    void on_button_clicked();

    //Member widgets:
    Gtk::Grid m_grid;
    Gtk::Button m_button;
    Gtk::Entry m_entry;
};

#endif