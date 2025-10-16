#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "../include/Deck.h"
#include "../include/Tower.h"

class Player {
 private:
  std::string name;
  Tower towers[3];
  Card* hand[3];
  Deck deck;

 public:
  Player(std::string name);

  const std::string& getName() const;
  Tower* getTowers();
  Card** getHand();

  void firstHandDraw();
  void playCard(Card* chosen, Tower& target);
  void drawCard(int index);
  bool isDefeated() const;
};

#endif