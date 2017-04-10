/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "Entity.h"

Entity::Entity(std::string imgLocation, sf::Rect<float> defaultHitbox)
        : sprite(sf::Sprite()),
          texture(sf::Texture()),
          timer(sf::Clock()),
          position(Viewport::Point<float>{0,0}),
          rotation(0),
          currentFrame(0,0,0,0,0,0),
          currentAnimation(AnimFrame::AnimType::none),
          currentAnimIndex(0),
          animations() {
    texture.loadFromFile(imgLocation);
    sprite.setTexture(texture);
    sprite.setTextureRect(Viewport::coordToPixel(defaultHitbox));
    this->defaultHitbox = defaultHitbox;
}

void Entity::setPos(Viewport::Point<float> pos) {
    position = pos;
    sprite.setPosition(position.x, position.y);
}

void Entity::setPos(float x, float y) {
    setPos(Viewport::Point<float>{x,y});
}

void Entity::setX(float x) {
    setPos(x, position.y);
}

void Entity::setY(float y) {
    setPos(position.x, y);
}

Viewport::Point<float> Entity::getPos() {
    return position;
}

void Entity::setRotation(float rot) {
    rotation = rot;
    sprite.setRotation(rot);
}

float Entity::getRotation() {
    return rotation;
}

const sf::Rect<float>& Entity::getDefaultHitbox() {
    return defaultHitbox;
}

void Entity::addAnimation(AnimFrame::AnimType type) {
    animations[type] = std::vector<AnimFrame>();
}

void Entity::addAnimation(AnimFrame::AnimType type, std::vector<AnimFrame> frames) {
    animations[type] = frames;
}

void Entity::removeAnimation(AnimFrame::AnimType type) {
    auto entry = animations.find(type);
    if(entry != animations.end())
        animations.erase(entry);
    else
        throw std::invalid_argument("Animation does not exist");
}

void Entity::addFrame(AnimFrame::AnimType type, AnimFrame frame) {
    animations[type].push_back(frame);
}

void Entity::addFrames(AnimFrame::AnimType type, std::vector<AnimFrame> frames) {
    animations[type] = frames;
}

std::vector<AnimFrame>& Entity::getAnimation(AnimFrame::AnimType type) {
    if (animations.find(type) != animations.end())
        return animations[type];
    else
        throw std::invalid_argument("Animation does not exist");
}

AnimFrame& Entity::getFrame(AnimFrame::AnimType type, int frameNum) {
    if (animations.find(type) != animations.end())
        if(animations[type].size()-1 < frameNum)
            return animations[type][frameNum];
        else
            throw std::invalid_argument("frameNum is larger than the vector size");
    else
        throw std::invalid_argument("Animation does not exist");
}

void Entity::setCurrentAnimtion(AnimFrame::AnimType type) {
    currentAnimation = type;
    currentAnimIndex= 0;
}

AnimFrame::AnimType Entity::getCurrentAnimation() {
    return currentAnimation;
}

void Entity::animCycle() {

    if(animations.size() >= 1)
        if (animations.begin()->first == AnimFrame::AnimType::none)
            if(sprite.getTextureRect() != animations[AnimFrame::AnimType::none][0].getSheet_frameBounds())
                sprite.setTextureRect(animations[AnimFrame::AnimType::none][0].getSheet_frameBounds());
        else
            if(timer.getElapsedTime().asSeconds() >= currentFrame.getFrameTime()) {
                auto& animation = getAnimation(currentAnimation);
                auto& frame = getFrame(currentAnimation, currentAnimIndex);
                currentFrame = frame;
                sprite.setTextureRect(frame.getSheet_frameBounds());
                if(currentAnimIndex-1 >= animation.size())
                    currentAnimIndex = 0;
                else
                    currentAnimIndex++;
                timer.restart();
            }
}

const sf::Sprite& Entity::getSprite() {
    return sprite;
}