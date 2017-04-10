/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

#ifndef FIRENFROST_LIVINGENTITY_H
#define FIRENFROST_LIVINGENTITY_H

#include "../Entity.h"
#include "../nonliving/loot/equippable/armour/Armour.h"
#include "../nonliving/loot/equippable/weapon/Weapon.h"

class LivingEntity : Entity {

public:
    LivingEntity(int health);

    const Armour& getArmour(std::string hitbox);
    void addArmour(std::string hitbox, Armour&);
    void removeArmour(std::string hitbox);

    virtual void onDeath();

protected:
    //String must be same as corresponding hitbox on entity
    std::map<std::string, Armour> armour;
    Weapon weapon;
};


#endif //FIRENFROST_LIVINGENTITY_H
