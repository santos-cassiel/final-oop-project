#ifndef HEALCARD_H
#define HEALCARD_H

#include "../include/Card.h"

class HealCard : public Card {
 public:
  HealCard(std::string name, int power);
  void applyAttack(Tower& target) override;
};

#endif