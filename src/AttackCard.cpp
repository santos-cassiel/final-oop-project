#include "../include/AttackCard.h"

AttackCard::AttackCard(std::string name, int power) : Card(name, power) {}

void AttackCard::applyAttack(Tower& target) { target.takeDamage(power); }