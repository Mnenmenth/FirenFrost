/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#ifndef FIRENFROST_ENTITY_H
#define FIRENFROST_ENTITY_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include "../core/Viewport.h"

class Entity {

public:
    struct Properties {
        Viewport::Dimension<double> size;
        Viewport::Point<double> position;
        sf::IntRect sheet_pos;
    };

    void setSize(double width, double height);
    void setSize(Viewport::Dimension<double> size);
    double getWidth();
    void setWidth(double);
    double getHeight();
    void setHeight(double);
    Viewport::Dimension<double> getSize();
    void setPos(Viewport::Point<double>);
    void setPos(double x, double y);
    void setX(double);
    void setY(double);
    Viewport::Point<double> getPos();
    void setProperties(const Properties);
    Properties getProperties();
protected:
    Entity(Properties, std::string imgLocation);
    Entity(Viewport::Dimension<double> size, sf::IntRect sheet_pos, Viewport::Point<double> draw_pos, std::string imgLocation);
    Entity(double width, double height, double sheet_x, double sheet_y, double draw_x, double draw_y, std::string imgLocation);
    ~Entity();
    sf::Sprite sprite;
    sf::Texture texture;
    Properties properties;
};


#endif //FIRENFROST_ENTITY_H
