#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../include/Player.h"
#include <iostream>
#include <chrono>
#include <thread>

class GameManager{
    private:
        Player player1;
        Player player2;
        Player* currentPlayer;
        int timer;
        bool gameOver;

    public:
        GameManager(const std::string& name1, const std::string& name2, int gameTime = 180);
        void startGame();

    public:
        void switchTurn();
        void checkGameStatus();
        void updateTimer();
        void endGame();
        void playerTurn(Player& current, Player& opponent);
        void displayStatus() const;
};

#endif