#include "Core.h"

Core::Core() = default;

Core::~Core() {
    ImGui::SFML::Shutdown();
}

int Core::init() {
    window.create(sf::VideoMode(width, height), "Core", sf::Style::Close);
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    embraceTheDarkness();
    return 1;
}

void Core::loop() {
    sf::Time elapsedTime = sf::Time::Zero;

    while (window.isOpen()) {
        elapsedTime += m_deltaClock.restart();
        handleEvents();

        if (elapsedTime > sf::seconds(1.f / loop_limit)) {
            ImGui::SFML::Update(window, m_deltaClock.restart());
            imgui();
            display();
        }
    }
}

void Core::handleEvents() {
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(window, event);

        switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) window.close();
                break;
        }
    }
}

void Core::display() {
    window.clear();
    ImGui::SFML::Render(window);
    window.display();
}

void Core::imgui() {

}