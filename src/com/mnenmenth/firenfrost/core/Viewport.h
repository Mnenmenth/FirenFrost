/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#ifndef FIRENFROST_COORDSYS_H
#define FIRENFROST_COORDSYS_H


class Viewport {

public:
    template <class T>
    struct Point {
        T x;
        T y;
    };

    template <class T>
    struct Dimension {
        T width;
        T height;
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
    static Point<int> coordToPixel(Point<double>);
private:
    static double aspectRatio;
    static Dimension<int> units;
    static Dimension<int> size;
};


#endif //FIRENFROST_COORDSYS_H
