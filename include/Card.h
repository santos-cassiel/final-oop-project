#ifndef CARD_H
#define CARD_H

#include "../include/Tower.h"

using namespace std;
#include <string>

class Card {
 protected:
  std::string name;
  int power;  // used power instead of damage name for variable to avoid
              // redundancy

 public:
  Card(std::string name, int power);
  virtual ~Card() = default;

  std::string getName() const;
  int getPower() const;

  virtual void applyAttack(Tower& target) = 0;
};

#endif