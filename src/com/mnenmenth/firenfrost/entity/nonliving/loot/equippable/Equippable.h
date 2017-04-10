/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

#ifndef FIRENFROST_EQUIPPABLE_H
#define FIRENFROST_EQUIPPABLE_H

#include "../Loot.h"
#include "../../../Hitbox.h"

class Equippable : Loot {
public:
    Equippable(std::string imageLocation, sf::Rect<float> defaultHitbox);

    void setAssociatedHitbox(Hitbox&);
    const Hitbox& getAssociatedHitbox();

protected:
    Loot::State state;
    Hitbox& associatedHitbox;
};


#endif //FIRENFROST_EQUIPPABLE_H
