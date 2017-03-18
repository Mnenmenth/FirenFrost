/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "Entity.h"

Entity::Entity(Properties prop, std::string imgLocation) {
    properties = prop;
    texture.loadFromFile(imgLocation);
    sprite = sf::Sprite(texture, prop.sheet_rect);
    sprite.setScale((float)(Viewport::coordToPixel(prop.size).width/prop.sheet_rect.width), (float)(Viewport::coordToPixel(prop.size).height/prop.sheet_rect.height));
}

Entity::Entity(Viewport::Dimension<double> size, sf::IntRect sheet_rect, Viewport::Point<double> pos, std::string imgLocation) {
    Entity(Properties{size, pos, sheet_rect}, imgLocation);
}

Entity::Entity(double width, double height, int sheet_width, int sheet_height, int sheet_x, int sheet_y, double draw_x, double draw_y, std::string imgLocation) {
    Entity(Viewport::Dimension<double>{width, height}, sf::IntRect(sheet_x, sheet_y, sheet_width, sheet_height), Viewport::Point<double>{draw_x, draw_y}, imgLocation);
}

void Entity::setSize(double width, double height) {
    setSize(Viewport::Dimension<double>{width, height});
}

void Entity::setSize(Viewport::Dimension<double> size) {
    properties.size = size;
    sprite.setScale((float)(Viewport::coordToPixel(properties.size).width/properties.sheet_rect.width), (float)(Viewport::coordToPixel(properties.size).height/properties.sheet_rect.height));
}

double Entity::getWidth() {
    return properties.size.width;
}

void Entity::setWidth(double width) {
    properties.size.width = width;
    sprite.setScale((float)(Viewport::coordToPixel(properties.size).width/properties.sheet_rect.width), 1.0f);
}

double Entity::getHeight() {
    return properties.size.height;
}

void Entity::setHeight(double height) {
    properties.size.height = height;
    sprite.setScale(1.0f, (float)(Viewport::coordToPixel(properties.size).height/properties.sheet_rect.height));
}

Viewport::Dimension<double> Entity::getSize() {
    return properties.size;
}

void Entity::setPos(Viewport::Point<double> pos) {
    properties.position = pos;
}

void Entity::setPos(double x, double y) {
    properties.position.x = x;
    properties.position.y = y;
}

void Entity::setX(double x) {
    properties.position.x = x;
}

void Entity::setY(double y) {
    properties.position.y = y;
}

Viewport::Point<double> Entity::getPos() {
    return properties.position;
}

void Entity::setProperties(Entity::Properties prop) {
    properties = prop;
}

Entity::Properties Entity::getProperties() {
    return properties;
}

Entity::~Entity() {

}

