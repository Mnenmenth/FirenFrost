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

class AnimFrame {
public:

    AnimFrame(Viewport::Dimension<double> size, sf::IntRect sheet_frameBounds);
    AnimFrame(double width, double height, int sheet_frameWidth, int sheet_frameHeight, int sheet_frameTop, int sheet_frameLeft);

    enum AnimType { none, idle, movement, attack };

    void setFrameTime(float);
    float getFrameTime();

    void setSize(double width, double height);
    void setSize(Viewport::Dimension<double> size);
    double getWidth();
    void setWidth(double);
    double getHeight();
    void setHeight(double);
    Viewport::Dimension<double> getSize();

    void setScale(float w, float h);
    Viewport::Dimension<float> getScale();

    void setRelativePos(Viewport::Point<double>);
    void setRelativeX(double);
    void setRelativeY(double);
    Viewport::Point<double> getRelativePos();

    void setRelativeRot(double);
    double getRelativeRot();

    void setSheet_frameBounds(sf::IntRect);
    sf::IntRect getSheet_frameBounds();

    void addHitbox(std::string, sf::Rect<double>);
    void removeHitbox(std::string);
    sf::Rect<double>& getHitbox(std::string);
private:
    float frameTime;
    sf::IntRect sheet_frameBounds;
    Viewport::Dimension<double> size;
    Viewport::Point<double> relativePos;
    double relativeRot;
    Viewport::Dimension<float> scale;
    sf::Rect<double> defaultHitbox;
    //Hitbox name matters: Ex, body will receive damage while weapon will deal damage
    std::map<std::string, sf::Rect<double>> hitboxes;
};


#endif //FIRENFROST_ANIMFRAME_H
