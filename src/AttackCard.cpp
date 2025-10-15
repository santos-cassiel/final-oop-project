#include "../include/AttackCard.h"

AttackCard::AttackCard(std::string name, int power, std::string attackType)
    : Card(name, power, "singleAtk") {
  this->attackType = attackType;
}

std::string AttackCard::getAttackType() const { return attackType; }

void AttackCard::applyAttack(Tower& target) { target.takeDamage(power); }