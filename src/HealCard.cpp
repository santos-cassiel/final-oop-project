#include "../include/HealCard.h"

HealCard::HealCard(std::string name, int power)
    : Card(name, power, "healing") {}

void HealCard::applyAttack(Tower& target) { target.healTower(power); }