/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

#include "AnimatedEntity.h"

AnimatedEntity::AnimatedEntity(Properties prop, std::string imgLocation) : Entity(prop, imgLocation) {

}


AnimatedEntity::AnimatedEntity(Viewport::Dimension<double> size, sf::IntRect sheet_rect, Viewport::Point<double> pos, std::string imgLocation)
        : AnimatedEntity(Properties{size, pos, sheet_rect}, imgLocation) {}

AnimatedEntity::AnimatedEntity(double width, double height, int sheet_width, int sheet_height, int sheet_x, int sheet_y, double draw_x, double draw_y, std::string imgLocation)
        : AnimatedEntity(Viewport::Dimension<double>{width, height}, sf::IntRect(sheet_x, sheet_y, sheet_width, sheet_height), Viewport::Point<double>{draw_x, draw_y}, imgLocation) {}
