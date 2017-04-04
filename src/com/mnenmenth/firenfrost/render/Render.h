/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#ifndef FIRENFROST_RENDER_H
#define FIRENFROST_RENDER_H

#include <SFML/Graphics.hpp>
#include <map>
#include "../core/Viewport.h"
#include "../entity/Entity.h"

class Render {
public:

    Render(std::string windowTitle, Viewport::Dimension<unsigned int> windowSize);
    Render(std::string windowTitle, unsigned int windowWidth, unsigned int windowHeight);

    void renderLoop();

    void setWindowSize(const sf::Vector2u&);
    void setWindowSize(const Viewport::Dimension<unsigned int>&);
    void setWindowSize(unsigned int, unsigned int);
    void setWindowWidth(unsigned int);
    void setWindowHeight(unsigned int);
    Viewport::Dimension<unsigned int> getWindowSize();
    sf::RenderWindow& getWindow();

    void addEntity(std::string name, Entity&);
    void removeEntity(std::string name);

private:
    sf::RenderWindow window;
    sf::View mainView;
    std::map<std::string, Entity&> renderList;
};


#endif //FIRENFROST_RENDER_H
