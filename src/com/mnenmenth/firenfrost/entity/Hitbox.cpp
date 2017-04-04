/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
#include "Hitbox.h"

Hitbox::Hitbox() {

}

bool Hitbox::collides(Hitbox& hitbox, CollisionType* type) {

    if(hitbox.getCollistionType() == none) *type = CollisionType::none;
    else if (hitbox.getCollistionType() == take_damage && collisionType == deal_damage) *type = CollisionType::deal_damage;
    else if (hitbox.getCollistionType() == deal_damage && collisionType == take_damage) *type = CollisionType::take_damage;

    return bounds.intersects(hitbox.getBounds());
}

void Hitbox::setCollistionType(CollisionType type) {
    collisionType = type;
}

CollisionType Hitbox::getCollistionType() {
    return collisionType;
}