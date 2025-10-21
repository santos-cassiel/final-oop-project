#include "../include/Tower.h"

#include <iostream>
#include <string>
using namespace std;

Tower::Tower() : name("Default"), health(100), destroyed(false) {}

Tower::Tower(string name, int health) {
  this->name = name;
  this->health = 100;  // default health is 100
  this->destroyed = false;
}

std::string Tower::getName() const { return name; }

int Tower::getHealth() const { return health; }

void Tower::takeDamage(int dmg) {
  if (health > 0) {
    health -= dmg;
  }
  if (health < 0) {
    health = 0;
  }
}

void Tower::healTower(int HP) {
  if (health < 300) {
    health += HP;
  }
  if (health > 300) {
    health = 300;
  }
}

bool Tower::isDestroyed() const {
  if (health <= 0) {
    return true;
  } else {
    return false;
  }
}