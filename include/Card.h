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
  std::string type;

 public:
  Card(std::string name, int power, std::string type);
  virtual ~Card() = default;

  std::string getName() const;
  std::string getType() const;
  int getPower() const;

  virtual void applyAttack(Tower& target) = 0;
};

#endif