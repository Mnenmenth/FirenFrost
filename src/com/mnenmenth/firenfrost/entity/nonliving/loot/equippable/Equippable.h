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

class Equippable : public Loot {
public:
    Equippable(std::string imageLocation, Hitbox defaultHitbox, Loot::State);
    ~Equippable();
    void setAssociatedHitbox(Hitbox&);
    Hitbox* const getAssociatedHitbox() const;

    bool const isEquipped() const;

protected:
    Loot::State state;
    Hitbox* associatedHitbox;
};


#endif //FIRENFROST_EQUIPPABLE_H
