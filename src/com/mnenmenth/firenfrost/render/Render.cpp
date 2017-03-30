/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "Render.h"
#include <iostream>

Render::Render(std::string windowTitle, Viewport::Dimension<unsigned int> windowSize) :
        window(sf::VideoMode(windowSize.width, windowSize.height), windowTitle) {
}

Render::Render(std::string windowTitle, unsigned int windowWidth, unsigned int windowHeight) :
        Render(windowTitle, Viewport::Dimension<unsigned int>{windowWidth, windowHeight}) {
}

void Render::renderLoop() {

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        if(!renderList.empty())
            for (auto &pair : renderList) {
                pair.second.animCycle();
                window.draw(pair.second.getSprite());
            }

        window.display();
    }

}

void Render::setWindowSize(Viewport::Dimension<unsigned int> size) {
    window.setSize(sf::Vector2u(size.width, size.height));
}

void Render::setWindowSize(unsigned int width, unsigned int height) {
    window.setSize(sf::Vector2u(width, height));
}

void Render::setWindowWidth(unsigned int width) {
    window.setSize(sf::Vector2u(width, window.getSize().y));
}

void Render::setWindowHeight(unsigned int height) {
    window.setSize(sf::Vector2u(window.getSize().y, height));
}

Viewport::Dimension<unsigned int> Render::getWindowSize() {
    return Viewport::Dimension<unsigned int>{window.getSize().x, window.getSize().y};
}

sf::RenderWindow& Render::getWindow() {
    return window;
}