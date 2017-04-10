/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

#include "Equippable.h"

Equippable::Equippable(std::string imageLocation, sf::Rect<float> defaultHitbox)
        : Loot(imageLocation, defaultHitbox),
          associatedHitbox(Hitbox()) {

}

