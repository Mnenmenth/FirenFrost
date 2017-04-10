/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include <cmath>
#include "Viewport.h"

float Viewport::aspectRatio = 0;
Viewport::Dimension<int> Viewport::units = Viewport::Dimension<int>{0,0};
Viewport::Dimension<int> Viewport::size = Viewport::Dimension<int>{0,0};

void Viewport::init(Dimension<int> size, float ratio, int xUnits) {
    units.width = xUnits;
    units.height = (int)ceil(xUnits/ratio);
    Viewport::size = size;
}

void Viewport::init(int width, int height, float ratio, int xUnits) {
    init(Dimension<int>{width, height}, ratio, xUnits);
}

void Viewport::setSize(Dimension<int> size) {
    Viewport::size = size;
}

void Viewport::setSize(int width, int height) {
    size.width = width;
    size.height = height;
}

void Viewport::setWidth(int width) {
    size.width = width;
}

void Viewport::setHeight(int height) {
    size.height = height;
}

Viewport::Dimension<int> Viewport::getSize() {
    return size;
}

void Viewport::setAspectRatio(float ratio) {
    aspectRatio = ratio;
    units.height = (int)ceil(units.width/ratio);
}
float Viewport::getAspectRatio() { return aspectRatio; }

Viewport::Point<float> Viewport::pixelToCoord(const Point<int>& pixel) {
    Point<float> coord{};
    if (pixel.x != 0)
        coord.x = (pixel.x / size.width) * units.width;
    if (pixel.y != 0)
        coord.y = (pixel.y/size.height)*units.height;
    return coord;
}

Viewport::Dimension<float> Viewport::pixelToCoord(const Dimension<int>& pixel) {
    Dimension<float> coord{};
    if (pixel.width != 0)
        coord.width = (pixel.width / size.width) * units.width;
    if (pixel.height != 0)
        coord.height = (pixel.height/size.height)*units.height;
    return coord;
}

sf::FloatRect Viewport::pixelToCoord(const sf::IntRect& pixel) {
    Point<float> corners = pixelToCoord(Point<int>{pixel.top, pixel.left});
    Dimension<float> size = pixelToCoord(Dimension<int>{pixel.width, pixel.height});
    return sf::FloatRect(corners.x, corners.y, size.width, size.height);
}

Viewport::Point<int> Viewport::coordToPixel(const Point<float>& coord) {
    Point<int> pixel{};
    if (coord.x != 0)
        pixel.x = (int)ceil((coord.x*size.width)/units.width);
    if (coord.y != 0)
        pixel.y = (int)ceil((coord.y*size.height)/units.height);
    return pixel;
}

Viewport::Dimension<int> Viewport::coordToPixel(const Dimension<float>& coord) {
    Dimension<int> pixel{};
    if (coord.width != 0)
        pixel.width = (int)ceil((coord.width*size.width)/units.width);
    if (coord.height != 0)
        pixel.height = (int)ceil((coord.height*size.height)/units.height);
    return pixel;
}

sf::IntRect Viewport::coordToPixel(const sf::FloatRect& coord) {
    Point<int> corners = coordToPixel(Point<float>{coord.top, coord.left});
    Dimension<int> size = coordToPixel(Dimension<float>{coord.width, coord.height});
    return sf::IntRect(corners.x, corners.y, size.width, size.height);
}