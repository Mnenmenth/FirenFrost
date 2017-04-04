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
    template <class T>
    struct Point {
        T x;
        T y;
        Point<int> toPixel() { return Viewport::coordToPixel(*this); }
        Point<float> toCoord() { return Viewport::pixelToCoord(*this); }
    };

    template <class T>
    struct Dimension {
        T width;
        T height;
        Dimension<int> toPixel() { return Viewport::coordToPixel(*this); }
        Dimension<float> toCoord() { return Viewport::pixelToCoord(*this); }
    };
    static void init(Dimension<int>, float ratio, int xUnits);
    static void init(int width, int height, float ratio, int xUnits);
    static void setSize(Dimension<int>);
    static void setSize(int width, int height);
    static void setWidth(int);
    static void setHeight(int);
    static Dimension<int> getSize();
    static void setAspectRatio(float);
    static float getAspectRatio();
    static Point<float> pixelToCoord(const Point<int>&);
    static Dimension<float> pixelToCoord(const Dimension<int>&);
    static sf::Rect<float> pixelToCoord(const sf::IntRect&);
    static Point<int> coordToPixel(const Point<float>&);
    static Dimension<int> coordToPixel(const Dimension<float>&);
    static sf::IntRect coordToPixel(const sf::Rect<float>&);
private:
    static float aspectRatio;
    static Dimension<int> units;
    static Dimension<int> size;
};


#endif //FIRENFROST_COORDSYS_H
