/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#ifndef FIRENFROST_COORDSYS_H
#define FIRENFROST_COORDSYS_H

#include <SFML/Graphics/Rect.hpp>

class Viewport {

public:
    //        Point<double>::hi();
    //        Point<int>::hi();
    template <class T>
    struct Point {
        T x;
        T y;
        Point<int> toPixel() { return Viewport::coordToPixel(*this); }
        Point<double> toCoord() { return Viewport::pixelToCoord(*this); }
    };

    template <class T>
    struct Dimension {
        T width;
        T height;
        Dimension<int> toPixel() { return Viewport::coordToPixel(*this); }
        Dimension<double> toCoord() { return Viewport::pixelToCoord(*this); }
    };
    static void init(Dimension<int>, double ratio, int xUnits);
    static void init(int width, int height, double ratio, int xUnits);
    static void setSize(Dimension<int>);
    static void setSize(int width, int height);
    static void setWidth(int);
    static void setHeight(int);
    static Dimension<int> getSize();
    static void setAspectRatio(double);
    static double getAspectRatio();
    static Point<double> pixelToCoord(Point<int>);
    static Dimension<double> pixelToCoord(Dimension<int>);
    static sf::Rect<double> pixelToCoord(sf::IntRect);
    static Point<int> coordToPixel(Point<double>);
    static Dimension<int> coordToPixel(Dimension<double>);
    static sf::IntRect coordToPixel(sf::Rect<double>);
private:
    static double aspectRatio;
    static Dimension<int> units;
    static Dimension<int> size;
};


#endif //FIRENFROST_COORDSYS_H
