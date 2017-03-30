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

    void setWindowSize(Viewport::Dimension<unsigned int>);
    void setWindowSize(unsigned int, unsigned int);
    void setWindowWidth(unsigned int);
    void setWindowHeight(unsigned int);
    Viewport::Dimension<unsigned int> getWindowSize();
    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow window;
    std::map<std::string, Entity&> renderList;
};


#endif //FIRENFROST_RENDER_H
