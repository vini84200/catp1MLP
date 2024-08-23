#include "Window.hpp"

#include <gtkmm/application.h>
#include <iostream>

HelloWorld::HelloWorld()
        : m_button("Hello World")
{
    // Sets the border width of the window.
    set_border_width(10);


    add(m_grid);
    m_grid.set_border_width(10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    m_button.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &HelloWorld::on_button_clicked));

    // This packs the button into the Window (a container).
    m_grid.attach(m_button, 0, 0);

    // The final step is to display this newly created widget...
    m_button.show();



    m_grid.attach(m_entry, 1, 0);
    m_entry.show();
    show_all_children();

}

HelloWorld::~HelloWorld()
{
    std::cout << "Goodbye World" << std::endl;
}

void HelloWorld::on_button_clicked()
{
    std::cout << "Hello World, " << m_entry.get_text() << std::endl;
}

