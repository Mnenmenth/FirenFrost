/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

#ifndef FIRENFROST_ANIMATEDENTITY_H
#define FIRENFROST_ANIMATEDENTITY_H

#include "Entity.h"

class AnimatedEntity : public Entity {

public:
    AnimatedEntity(Properties, std::string imgLocation);
    AnimatedEntity(Viewport::Dimension<double> size, sf::IntRect sheet_rect, Viewport::Point<double> draw_pos, std::string imgLocation);
    AnimatedEntity(double width, double height, int sheet_width, int sheet_height, int sheet_x, int sheet_y, double draw_x, double draw_y, std::string imgLocation);
};


#endif //FIRENFROST_ANIMATEDENTITY_H
