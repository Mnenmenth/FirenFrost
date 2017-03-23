/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "AnimFrame.h"
#include <stdexcept>

AnimFrame::AnimFrame(Viewport::Dimension<double> size, sf::IntRect sheet_rect) {
    setSize(size);
    defaultHitbox = Viewport::pixelToCoord(sheet_rect);
}

AnimFrame::AnimFrame(double width, double height, int sheet_frameWidth, int sheet_frameHeight, int sheet_frameTop, int sheet_frameLeft) {
    AnimFrame(Viewport::Dimension<double>{width, height}, sf::IntRect(sheet_frameWidth, sheet_frameHeight, sheet_frameTop, sheet_frameLeft));
}

void AnimFrame::setFrameTime(float time) {
    frameTime = time;
}

float AnimFrame::getFrameTime() {
    return frameTime;
}

void AnimFrame::setSize(double width, double height) {
    setSize(Viewport::Dimension<double>{width, height});
}

void AnimFrame::setSize(Viewport::Dimension<double> size) {
    this->size = size;
    setScale((float)(this->size.toPixel().width/sheet_frameBounds.width), (float)(this->size.toPixel().height/sheet_frameBounds.height));
}

double AnimFrame::getWidth() {
    return size.width;
}

void AnimFrame::setWidth(double width) {
    size.width = width;
    setScale((float)(size.toPixel().width/sheet_frameBounds.width), 1.0f);
}

double AnimFrame::getHeight() {
    return size.height;
}

void AnimFrame::setHeight(double height) {
    size.height = height;
    setScale(1.0f, (float)(size.toPixel().height/sheet_frameBounds.height));
}

Viewport::Dimension<double> AnimFrame::getSize() {
    return size;
}

void AnimFrame::setRelativePos(Viewport::Point<double> pos) {
    relativePos = pos;
}

void AnimFrame::setRelativeX(double x) {
    relativePos.x = x;
}

void AnimFrame::setRelativeY(double y) {
    relativePos.y = y;
}

Viewport::Point AnimFrame::getRelativePos() {
    return relativePos;
}

void AnimFrame::setScale(float width, float height) {
    scale = Viewport::Dimension<float>{width, height};
}

Viewport::Dimension<float> AnimFrame::getScale() {
    return scale;
}

void AnimFrame::setSheet_frameBounds(sf::IntRect bounds) {
    sheet_frameBounds = bounds;
}

sf::IntRect AnimFrame::getSheet_frameBounds() {
    return sheet_frameBounds;
}

void AnimFrame::addHitbox(std::string name, sf::Rect<double> hitbox) {
    hitboxes[name] = hitbox;
}

void AnimFrame::removeHitbox(std::string name) {
    auto entry = hitboxes.find(name);
    if(entry != hitboxes.end())
        hitboxes.erase(entry);
    else
        throw std::invalid_argument(name + " is not a hitbox");
}

sf::Rect<double>& AnimFrame::getHitbox(std::string name) {
    auto entry = hitboxes.find(name);
    if (entry != hitboxes.end())
        return hitboxes[name];
    else
        throw std::invalid_argument(name + " is not a hitbox");
}

AnimFrame::~AnimFrame() {

}

