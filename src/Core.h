#ifndef TEMPLATE_CORE_H
#define TEMPLATE_CORE_H

#include "Libraries.h"

#define width 600
#define height 600
#define loop_limit 60

class Core {

private:

    sf::RenderWindow window;

    sf::Event event{};

    sf::Clock m_deltaClock;

public:

    Core();

    ~Core();

    int init();

    void loop();

    void handleEvents();

    void display();

    void imgui();
};


#endif
