/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "Render.h"
#include <iostream>
#include <math.h>

Render::Render(std::string windowTitle, Viewport::Dimension<unsigned int> windowSize) :
        window(sf::VideoMode(windowSize.width, windowSize.height), windowTitle),
        mainView(sf::View()) {
    mainView.setSize(windowSize.width, windowSize.height);
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
                if(Viewport::coordToPixel(pair.second.getDefaultHitbox())
                        .intersects(sf::IntRect(0, 0, (int)floorf(mainView.getSize().x),
                                                (int)floorf(mainView.getSize().y)))) {
                    pair.second.animCycle();
                    window.draw(pair.second.getSprite());
                }
            }

        window.display();
    }

}

void Render::setWindowSize(const sf::Vector2u& size) {
    window.setSize(size);
    mainView.setSize(sf::Vector2f(size.x, size.y));
}

void Render::setWindowSize(const Viewport::Dimension<unsigned int>& size) {
    setWindowSize(sf::Vector2u(size.width, size.height));
}

void Render::setWindowSize(unsigned int width, unsigned int height) {
    setWindowSize(sf::Vector2u(width, height));
}

void Render::setWindowWidth(unsigned int width) {
    setWindowSize(sf::Vector2u(width, getWindowSize().height));
}

void Render::setWindowHeight(unsigned int height) {
    setWindowSize(getWindowSize().height, height);
}

Viewport::Dimension<unsigned int> Render::getWindowSize() {
    return Viewport::Dimension<unsigned int>{window.getSize().x, window.getSize().y};
}

sf::RenderWindow& Render::getWindow() {
    return window;
}

void Render::addEntity(std::string name, Entity &entity) {
    renderList[name] = entity;
}

void Render::removeEntity(std::string name) {
    auto entry = renderList.find(name);
    if(entry != renderList.end())
        renderList.erase(entry);
    else
        throw std::invalid_argument("Enttiy does not exist in render list");
}