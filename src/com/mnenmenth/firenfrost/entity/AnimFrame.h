/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#ifndef FIRENFROST_ANIMFRAME_H
#define FIRENFROST_ANIMFRAME_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <map>
#include "../core/Viewport.h"
#include "Hitbox.h"

class AnimFrame {
public:

    AnimFrame(Viewport::Dimension<float> size, sf::IntRect sheet_frameBounds);
    AnimFrame(float width, float height, int sheet_frameWidth, int sheet_frameHeight, int sheet_frameTop, int sheet_frameLeft);

    enum AnimType { none, idle, movement, attack };

    void setFrameTime(float);
    float getFrameTime();

    void setSize(float width, float height);
    void setSize(Viewport::Dimension<float> size);
    float getWidth();
    void setWidth(float);
    float getHeight();
    void setHeight(float);
    Viewport::Dimension<float> getSize();

    void setScale(float w, float h);
    Viewport::Dimension<float> getScale();

    void setRelativePos(Viewport::Point<float>);
    void setRelativeX(float);
    void setRelativeY(float);
    Viewport::Point<float> getRelativePos();

    void setRelativeRot(float);
    float getRelativeRot();

    void setSheet_frameBounds(sf::IntRect);
    sf::IntRect getSheet_frameBounds();

    void addHitbox(std::string, sf::Rect<float>);
    void removeHitbox(std::string);
    sf::Rect<float>& getHitbox(std::string);
private:
    float frameTime;
    sf::IntRect sheet_frameBounds;
    Viewport::Dimension<float> size;
    Viewport::Point<float> relativePos;
    float relativeRot;
    Viewport::Dimension<float> scale;
    Hitbox defaultHitbox;
    //Hitbox name matters: Ex, body will receive damage while weapon will deal damage
    std::map<std::string, Hitbox> hitboxes;
};


#endif //FIRENFROST_ANIMFRAME_H
