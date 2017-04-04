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
    enum CollisionType { none, standard, take_damage, deal_damage, pickup, pickupee };
    Hitbox();
    void setCollistionType(CollisionType);
    CollisionType getCollistionType();

    bool collides(Hitbox&, CollisionType*);

    void setBounds(sf::FloatRect);
    sf::FloatRect getBounds();
private:
    sf::FloatRect bounds;
    CollisionType collisionType;
};


#endif //FIRENFROST_HITBOX_H
