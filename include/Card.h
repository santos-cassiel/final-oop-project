#ifndef CARD_H
#define CARD_H

#include "../include/Tower.h"

using namespace std;
#include <string>

class Card {
 private:
  string name;
  int damage;
  string type;  // attack or heal card

 public:
  virtual void applyAttack(Tower& target) = 0;
  int getDamage() const;
  string getName() const;
};

#endif