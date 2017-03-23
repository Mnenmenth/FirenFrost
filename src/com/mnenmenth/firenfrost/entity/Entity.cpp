/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "Entity.h"
#include <stdexcept>

Entity::Entity(Properties prop, std::string imgLocation) {
    setProperties(prop);
    texture.loadFromFile(imgLocation);
    sprite.setTexture(texture);

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
    sprite.setScale((float)(properties.size.toPixel().width/properties.sheet_rect.width), (float)(properties.size.toPixel().height/properties.sheet_rect.height));
}

double Entity::getWidth() {
    return properties.size.width;
}

void Entity::setWidth(double width) {
    properties.size.width = width;
    sprite.setScale((float)(properties.size.toPixel().width/properties.sheet_rect.width), 1.0f);
}

double Entity::getHeight() {
    return properties.size.height;
}

void Entity::setHeight(double height) {
    properties.size.height = height;
    sprite.setScale(1.0f, (float)(properties.size.toPixel().height/properties.sheet_rect.height));
}

Viewport::Dimension<double> Entity::getSize() {
    return properties.size;
}

void Entity::setPos(Viewport::Point<double> pos) {
    properties.position = pos;
    sprite.setPosition((float)properties.position.x, (float)properties.position.y);
}

void Entity::setPos(double x, double y) {
    setPos(Viewport::Point<double>{x,y});
}

void Entity::setX(double x) {
    setPos(x, properties.position.y);
}

void Entity::setY(double y) {
    setPos(properties.position.x, y);
}

Viewport::Point<double> Entity::getPos() {
    return properties.position;
}

void Entity::setProperties(Entity::Properties prop) {
    properties = prop;
    sprite.setTextureRect(properties.sheet_rect);
    sprite.setScale((float)(properties.size.toPixel().width/properties.sheet_rect.width), (float)(properties.size.toPixel().height/properties.sheet_rect.height));
}

Entity::Properties Entity::getProperties() {
    return properties;
}

void Entity::addHitbox(std::string name, sf::Rect<double> hitbox) {
    hitboxes[name] = hitbox;
}

void Entity::removeHitbox(std::string name) {
    auto entry = hitboxes.find(name);
    if(entry != hitboxes.end()) {
        hitboxes.erase(entry);
    }
}

sf::Rect<double> Entity::getHitbox(std::string name) {
    auto entry = hitboxes.find(name);
    if (entry != hitboxes.end())
        return hitboxes[name];
    else
        throw std::invalid_argument(name + " is not in the hitbox list");
}

Entity::~Entity() {

}

