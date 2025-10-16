#include "../include/Player.h"

#include <iostream>

Player::Player(std::string name) { this->name = name; }

void Player::firstHandDraw() {
  for (int i = 0; i < 3; i++) {
    hand[i] = deck.drawCard(hand, 3);
  }
}

void Player::playCard(Card* chosen, Tower& target) {
  if (!chosen) return;

  chosen->applyAttack(target);

  for (int i = 0; i < 3; i++) {
    if (hand[i] == chosen) {
      hand[i] = deck.drawCard(hand, 3);
      break;
    }
  }
}

void Player::drawCard(int index) {
  if (index >= 0 && index <= 3) {
    hand[index] = deck.drawCard(hand, 3);
  }
}

bool Player::isDefeated() const {
  for (int i = 0; i < 3; i++) {
    if (!towers[i].isDestroyed()) return false;
  }

  return true;
}

const std::string& Player::getName() const { return name; }

Tower* Player::getTowers() { return towers; }

Card** Player::getHand() { return hand; }