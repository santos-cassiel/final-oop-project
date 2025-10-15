#include "../include/Card.h"

Card::Card(std::string name, int power, std::string type) {
  this->name = name;
  this->power = power;
  this->type = type;
}

std::string Card::getName() const { return name; }

std::string Card::getType() const { return type; }

int Card::getPower() const { return power; }