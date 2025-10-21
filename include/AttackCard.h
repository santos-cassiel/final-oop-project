#ifndef ATTACKCARD_H
#define ATTACKCARD_H

#include "../include/Card.h"

class AttackCard : public Card {
 protected:
  std::string attackType;

 public:
  AttackCard(std::string name, int power);

  void applyAttack(Tower& target) override;
};

#endif