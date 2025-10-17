#ifndef TOWER_H
#define TOWER_H

#include <string>

class Tower {
 private:
  std::string name;
  int health;
  bool destroyed;

 public:
  Tower();
  Tower(std::string name, int health);
  std::string getName() const;
  int getHealth() const;

  virtual void takeDamage(int dmg);
  void healTower(int HP);
  bool isDestroyed() const;
};

#endif