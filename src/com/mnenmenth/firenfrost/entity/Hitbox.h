/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#ifndef FIRENFROST_HITBOX_H
#define FIRENFROST_HITBOX_H

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Rect.hpp>

class Hitbox {
public:
    enum CollisionType {
        TYPE_NONE,
        TYPE_SOLID,
        TYPE_MOVABLE,
        TYPE_TAKE_DAMAGE,
        TYPE_DEAL_DAMAGE,
        TYPE_LOOT,
        TYPE_CAN_PICKUP
    };
    enum CollisionAction {
        ACTION_NONE,
        ACTION_STOP,
        ACTION_TAKE_DAMAGE,
        ACTION_DEAL_DAMAGE,
        ACTION_PICKUP
    };
    Hitbox();
    void setCollistionType(CollisionType);
    Hitbox::CollisionType getCollistionType();

    bool collides(Hitbox&, CollisionAction&);

    void setBounds(sf::FloatRect);
    sf::FloatRect getBounds();
private:
    sf::FloatRect bounds;
    CollisionType collisionType;
};


#endif //FIRENFROST_HITBOX_H
