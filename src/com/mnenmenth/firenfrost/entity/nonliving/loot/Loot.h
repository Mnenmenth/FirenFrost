/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

#ifndef FIRENFROST_LOOT_H
#define FIRENFROST_LOOT_H

#include "../../Entity.h"

class Loot : Entity {
public:
    enum State { STATE_IN_INVENTORY, STATE_DROPPED, STATE_EQUIPPED };

    Loot(std::string imgLocation, Hitbox defaultHitbox);

    void setState(Loot::State);
    Loot::State getState();

protected:
    Loot::State state;
};


#endif //FIRENFROST_LOOT_H
