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
#include <map>
#include "../core/Viewport.h"

class Entity {

public:
    struct Properties {
        Viewport::Dimension<double> size;
        Viewport::Point<double> position;
        sf::IntRect sheet_rect;
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

    void addHitbox(std::string, sf::Rect<double>);
    void removeHitbox(std::string);
    sf::Rect<double> getHitbox(std::string);
protected:
    /*
     * Doubles are coordinates, ints are pixels
     */
    Entity(Properties, std::string imgLocation);
    Entity(Viewport::Dimension<double> size, sf::IntRect sheet_rect, Viewport::Point<double> draw_pos, std::string imgLocation);
    Entity(double width, double height, int sheet_width, int sheet_height, int sheet_x, int sheet_y, double draw_x, double draw_y, std::string imgLocation);
    ~Entity();
    sf::Sprite sprite;
    sf::Texture texture;
    Properties properties;
    sf::Rect<double> defaultHitbox;
    std::map<std::string, sf::Rect<double>> hitboxes;
};


#endif //FIRENFROST_ENTITY_H
