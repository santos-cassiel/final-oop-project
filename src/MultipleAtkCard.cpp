#include "../include/MultipleAtkCard.h"

MultipleAtkCard::MultipleAtkCard(std::string name, int power,
                                 std::string attackType, int numTargets)
    : AttackCard(name, power, "multipleAtk") {
  this->numTargets = numTargets;
}

void MultipleAtkCard::applyAttack(Tower targets[], int count) {
  for (int i = 0; i < count && i < numTargets; i++) {
    targets[i].takeDamage(power);
  }
}