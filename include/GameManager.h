#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <chrono>
#include <iostream>
#include <thread>

#include "../include/Player.h"

class GameManager {
 private:
  Player player1;
  Player player2;
  Player* currentPlayer;
  bool gameOver;

  std::chrono::steady_clock::time_point startTime;
  int timeLimit;

  void clearScreen();

 public:
  GameManager(const std::string& name1, const std::string& name2);
  void startGame();

 public:
  void switchTurn();
  void checkGameStatus();
  void updateTimer();
  void endGame();
  void playerTurn(Player& current, Player& opponent);
  void displayStatus();
};

#endif