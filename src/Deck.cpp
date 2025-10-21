#include "../include/Deck.h"

#include <iostream>

Deck::Deck() {
  // seed the rand generator
  srand(static_cast<unsigned>(time(nullptr)));

  // initialize card pool
  cards.push_back(new AttackCard("[Single Tower Attack] Fireball", 60));
  cards.push_back(new AttackCard("[Single Tower Attack] Cannon Shot", 40));
  cards.push_back(new AttackCard("[Single Tower Attack] Lightning Strike", 15));
  cards.push_back(
      new MultipleAtkCard("[Multiple Tower Attack] Arrow Volley", 30, 3));
  cards.push_back(
      new MultipleAtkCard("[Multiple Tower Attack] Blazing Barrage", 25, 3));
  cards.push_back(new HealCard("[Single Tower Healing] Repair Kit", 30));
}

Card* Deck::drawCard(Card* excluded[], int count) {
  if (cards.empty()) return nullptr;

  int attempts = 0;
  const int maxAttempts = 100;

  while (attempts < maxAttempts) {
    int index = rand() % cards.size();
    Card* tempDraw = cards[index];

    bool duplicate = false;
    for (int i = 0; i < count; i++) {
      if (excluded[i] && excluded[i]->getName() == tempDraw->getName()) {
        duplicate = true;
        break;
      }
    }

    if (!duplicate) {
      return tempDraw;
    }

    attempts++;
  }

  return cards[0];
}

int Deck::size() const { return static_cast<int>(cards.size()); }