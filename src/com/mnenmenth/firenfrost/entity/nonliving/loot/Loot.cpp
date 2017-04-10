/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

#include "Loot.h"

Loot::Loot(std::string imgLocation, sf::Rect<float> defaultHitbox) : Entity(imgLocation, defaultHitbox) {

}

void Loot::setState(Loot::State state) {
    this->state = state;
}

Loot::State Loot::getState() {
    return state;
}