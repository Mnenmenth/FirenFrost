/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include <cmath>
#include "Viewport.h"

double Viewport::aspectRatio = 0;
Viewport::Dimension<int> Viewport::units = Viewport::Dimension<int>{0,0};
Viewport::Dimension<int> Viewport::size = Viewport::Dimension<int>{0,0};

void Viewport::init(Dimension<int> size, double ratio, int xUnits) {
    units.width = xUnits;
    units.height = (int)ceil(xUnits/ratio);
    Viewport::size = size;
}

void Viewport::init(int width, int height, double ratio, int xUnits) {
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

void Viewport::setAspectRatio(double ratio) {
    aspectRatio = ratio;
    units.height = (int)ceil(units.width/ratio);
}
double Viewport::getAspectRatio() { return aspectRatio; }

Viewport::Point<double> Viewport::pixelToCoord(Point<int> pixel) {
    Point<double> coord{};
    if (pixel.x != 0)
        coord.x = (pixel.x / size.width) * units.width;
    if (pixel.y != 0)
        coord.y = (pixel.y/size.height)*units.height;
    return coord;
}

Viewport::Dimension<double> Viewport::pixelToCoord(Dimension<int> pixel) {
    Dimension<double> coord{};
    if (pixel.width != 0)
        coord.width = (pixel.width / size.width) * units.width;
    if (pixel.height != 0)
        coord.height = (pixel.height/size.height)*units.height;
    return coord;
}

Viewport::Point<int> Viewport::coordToPixel(Point<double> coord) {
    Point<int> pixel{};
    if (coord.x != 0)
        pixel.x = (int)ceil((coord.x*size.width)/units.width);
    if (coord.y != 0)
        pixel.y = (int)ceil((coord.y*size.height)/units.height);
    return pixel;
}

Viewport::Dimension<int> Viewport::coordToPixel(Dimension<double> coord) {
    Dimension<int> pixel{};
    if (coord.width != 0)
        pixel.width = (int)ceil((coord.width*size.width)/units.width);
    if (coord.height != 0)
        pixel.height = (int)ceil((coord.height*size.height)/units.height);
    return pixel;
}