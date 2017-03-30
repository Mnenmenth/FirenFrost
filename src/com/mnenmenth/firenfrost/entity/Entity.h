/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#ifndef FIRENFROST_ENTITY_H
#define FIRENFROST_ENTITY_H

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include "../core/Viewport.h"
#include "AnimFrame.h"

class Entity {
public:
    Entity(std::string imgLocation);
    void setPos(Viewport::Point<double>);
    void setPos(double x, double y);
    void setX(double);
    void setY(double);
    Viewport::Point<double> getPos();

    void setRotation(double);
    double getRotation();

    void addAnimation(AnimFrame::AnimType, std::vector<AnimFrame>);
    void addAnimation(AnimFrame::AnimType);
    void removeAnimation(AnimFrame::AnimType);
    void addFrame(AnimFrame::AnimType, AnimFrame);
    void addFrames(AnimFrame::AnimType, std::vector<AnimFrame>);
    std::vector<AnimFrame>& getAnimation(AnimFrame::AnimType);
    AnimFrame& getFrame(AnimFrame::AnimType, int frameNum);

    void setCurrentAnimtion(AnimFrame::AnimType);
    AnimFrame::AnimType getCurrentAnimation();

    void animCycle();

    sf::Sprite& getSprite();

protected:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock timer;
    Viewport::Point<double> position;
    double rotation;
    AnimFrame::AnimType currentAnimation;
    AnimFrame currentFrame;
    int currentAnimIndex;
    std::map<AnimFrame::AnimType, std::vector<AnimFrame>> animations;
};


#endif //FIRENFROST_ENTITY_H
