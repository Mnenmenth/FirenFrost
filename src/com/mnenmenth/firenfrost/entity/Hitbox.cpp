/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "Hitbox.h"

Hitbox::Hitbox() {

}

bool Hitbox::collides(Hitbox& hitbox, CollisionAction& action) {

    if (hitbox.getCollistionType() == TYPE_TAKE_DAMAGE
        && getCollistionType() == TYPE_DEAL_DAMAGE) action = ACTION_DEAL_DAMAGE;
    else if (hitbox.getCollistionType() == TYPE_DEAL_DAMAGE
             && getCollistionType() == TYPE_TAKE_DAMAGE) action = ACTION_TAKE_DAMAGE;
    else if (hitbox.getCollistionType() == TYPE_LOOT
             && getCollistionType() == TYPE_CAN_PICKUP) action = ACTION_PICKUP;
    else if (hitbox.getCollistionType() == TYPE_SOLID
             && getCollistionType() == TYPE_MOVABLE) action = ACTION_STOP;
    else action = ACTION_NONE;

    return bounds.intersects(hitbox.getBounds());
}

void Hitbox::setCollistionType(CollisionType type) {
    collisionType = type;
}

Hitbox::CollisionType Hitbox::getCollistionType() {
    return collisionType;
}

void Hitbox::setBounds(sf::FloatRect rect) {
    bounds = rect;
}

sf::FloatRect Hitbox::getBounds() {
    return bounds;
}