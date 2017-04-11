/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

#include "Equippable.h"


Equippable::Equippable(std::string imageLocation, Hitbox defaultHitbox, Loot::State state = Loot::State::STATE_NONE)
        : Loot(imageLocation, defaultHitbox),
          associatedHitbox(nullptr) {
}

Equippable::~Equippable() {
    delete associatedHitbox;
    associatedHitbox = NULL;
}

void Equippable::setAssociatedHitbox(Hitbox& hitbox) {
    *associatedHitbox = hitbox;
}

Hitbox* const Equippable::getAssociatedHitbox() const {
    return associatedHitbox;
}

bool const Equippable::isEquipped() const {
    return state == Loot::State::STATE_EQUIPPED;
}