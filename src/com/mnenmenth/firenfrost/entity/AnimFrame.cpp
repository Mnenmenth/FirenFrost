/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "AnimFrame.h"
#include <stdexcept>

AnimFrame::AnimFrame(Viewport::Dimension<float> size, sf::IntRect sheet_rect) : defaultHitbox(Hitbox()) {
    setSize(size);
    defaultHitbox.setBounds(Viewport::pixelToCoord(sheet_rect));
}

AnimFrame::AnimFrame(float width, float height, int textureWidth, int textureHeight, int textureTop, int textureLeft) {
    AnimFrame(Viewport::Dimension<float>{width, height}, sf::IntRect(textureWidth, textureHeight, textureTop, textureLeft));
}

void AnimFrame::setFrameTime(float time) {
    frameTime = time;
}

float AnimFrame::getFrameTime() {
    return frameTime;
}

void AnimFrame::setSize(float width, float height) {
    setSize(Viewport::Dimension<float>{width, height});
}

void AnimFrame::setSize(Viewport::Dimension<float> size) {
    this->size = size;
    setScale((float)(this->size.toPixel().width/textureRect.width), (float)(this->size.toPixel().height/textureRect.height));
}

float AnimFrame::getWidth() {
    return size.width;
}

void AnimFrame::setWidth(float width) {
    size.width = width;
    setScale((float)(size.toPixel().width/textureRect.width), 1.0f);
}

float AnimFrame::getHeight() {
    return size.height;
}

void AnimFrame::setHeight(float height) {
    size.height = height;
    setScale(1.0f, (float)(size.toPixel().height/textureRect.height));
}

Viewport::Dimension<float> AnimFrame::getSize() {
    return size;
}

void AnimFrame::setRelativePos(Viewport::Point<float> pos) {
    relativePos = pos;
}

void AnimFrame::setRelativeX(float x) {
    relativePos.x = x;
}

void AnimFrame::setRelativeY(float y) {
    relativePos.y = y;
}

Viewport::Point<float> AnimFrame::getRelativePos() {
    return relativePos;
}

void AnimFrame::setRelativeRot(float rot) {
    relativeRot = rot;
}

float AnimFrame::getRelativeRot() {
    return relativeRot;
}

void AnimFrame::setScale(float width, float height) {
    scale = Viewport::Dimension<float>{width, height};
}

Viewport::Dimension<float> AnimFrame::getScale() {
    return scale;
}

void AnimFrame::setSheet_frameBounds(sf::IntRect bounds) {
    textureRect = bounds;
}

sf::IntRect AnimFrame::getSheet_frameBounds() {
    return textureRect;
}

void AnimFrame::addHitbox(std::string name, Hitbox hitbox) {
    hitboxes[name] = hitbox;
}

void AnimFrame::removeHitbox(std::string name) {
    auto entry = hitboxes.find(name);
    if(entry != hitboxes.end())
        hitboxes.erase(entry);
    else
        throw std::invalid_argument(name + " is not a hitbox");
}

Hitbox& AnimFrame::getHitbox(std::string name) {
    auto entry = hitboxes.find(name);
    if (entry != hitboxes.end())
        return hitboxes[name];
    else
        throw std::invalid_argument(name + " is not a hitbox");
}