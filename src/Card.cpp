#include "../include/Card.h"

Card::Card(std::string name, int power) {
  this->name = name;
  this->power = power;
}

std::string Card::getName() const { return name; }

int Card::getPower() const { return power; }