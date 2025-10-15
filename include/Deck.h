#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include <ctime>
#include <vector>

#include "../include/AttackCard.h"
#include "../include/Card.h"
#include "../include/HealCard.h"
#include "../include/MultipleAtkCard.h"

class Deck {
 private:
  std::vector<Card*> cards;

 public:
  Deck();
  Card* drawCard(Card* excluded[], int count);
  int size() const;
};

#endif