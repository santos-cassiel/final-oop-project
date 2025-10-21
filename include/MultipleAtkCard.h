#ifndef MULTIPLEATKCARD_H
#define MULTIPLEATKCARD_H

#include "../include/AttackCard.h"

class MultipleAtkCard : public AttackCard {
 private:
  int numTargets;

 public:
  MultipleAtkCard(std::string name, int power, int numTargets);

  void applyAttack(Tower targets[], int count);
};

#endif