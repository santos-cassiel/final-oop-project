#include "../include/GameManager.h"
using namespace std;

GameManager::GameManager(const std::string& name1, const std::string& name2)
    : player1(name1),
      player2(name2),
      gameOver(false),
      currentPlayer(&player1),
      timeLimit(180) {
  player1.firstHandDraw();
  player2.firstHandDraw();
}

void GameManager::startGame() {
  cout << "Tower Game" << endl;
  cout << player1.getName() << " vs " << player2.getName() << endl;
  startTime = chrono::steady_clock::now();

  while (!gameOver) {
    updateTimer();
    if (gameOver) break;

    displayStatus();

    Player* opponent;
    if (currentPlayer == &player1) {
      opponent = &player2;
    } else {
      opponent = &player1;
    }

    playerTurn(*currentPlayer, *opponent);
    checkGameStatus();
    switchTurn();
  }

  endGame();
}

void GameManager::displayStatus() {
  using namespace std::chrono;

  auto now = steady_clock::now();
  int elapsed = duration_cast<seconds>(now - startTime).count();

  cout << endl << " Time elapsed: " << elapsed << " seconds" << endl;

  cout << player1.getName() << " Towers: " << endl;
  for (int i = 0; i < 3; i++) {
    cout << " T" << i + 1 << ": " << player1.getTowers()[i].getHealth() << " HP"
         << endl;
  }
  cout << endl;

  cout << player2.getName() << " Towers: " << endl;
  for (int i = 0; i < 3; i++) {
    cout << " T" << i + 1 << ": " << player2.getTowers()[i].getHealth() << " HP"
         << endl;
  }
  cout << endl;
}

void GameManager::playerTurn(Player& current, Player& opponent) {
  if (current.isDefeated()) return;

  cout << current.getName() << "'s turn: " << endl;

  Card** hand = current.getHand();
  for (int i = 0; i < 3; i++) {
    if (hand[i]) {
      cout << "[" << i + 1 << "] " << hand[i]->getName()
           << ", Damage: " << hand[i]->getPower() << endl;
    } else {
      cout << "[" << i + 1 << "] Empty slot" << endl;
    }
  }

  int choice = 0;
  Card* chosen = nullptr;

  while (true) {
    int tempChoice = 0;
    cout << "Choose card [1-3]: ";
    cin >> tempChoice;
    if (tempChoice >= 1 && tempChoice <= 3) {
      choice = tempChoice;

      chosen = hand[choice - 1];

      string cardType = chosen->getType();

      if (cardType == "healing") {
        bool validTarget = false;
        for (int i = 0; i < 3; i++) {
          Tower& tower = current.getTowers()[i];
          if (!tower.isDestroyed() && tower.getHealth() < 100) {
            validTarget = true;
            break;
          }
        }

        if (!validTarget) {
          cout << "No ally tower can be healed. Choose a different card"
               << endl;
          continue;
        }
      }

      break;

    } else {
      cout << "Invalid choice try again." << endl;
    }
  }

  string cardType = chosen->getType();

  if (cardType == "attack") {
    int targetTower = 0;
    Tower* target = nullptr;
    while (true) {
      int tempTarget = 0;
      cout << "Choose opponent tower to attack [1-3]: ";
      cin >> tempTarget;

      if (tempTarget >= 1 && tempTarget <= 3) {
        targetTower = tempTarget;

        target = &opponent.getTowers()[targetTower - 1];

        if (target->getHealth() > 0) {
          break;
        }

      } else {
        cout << "Invalid choice try again." << endl;
      }
    }

    cout << current.getName() << " used " << chosen->getName()
         << " to attack tower " << targetTower << " of " << opponent.getName()
         << endl;
    current.playCard(chosen, *target);
  } else if (cardType == "healing") {
    int targetTower = 0;
    Tower* target = nullptr;
    while (true) {
      int tempTarget = 0;
      cout << "Choose ally tower to heal [1-3]: ";
      cin >> tempTarget;

      if (tempTarget >= 1 && tempTarget <= 3) {
        targetTower = tempTarget;

        target = &current.getTowers()[targetTower - 1];

        if (target->getHealth() > 0 && target->getHealth() < 100) {
          break;
        }

      } else {
        cout << "Invalid choice try again." << endl;
      }
    }

    cout << current.getName() << " used " << chosen->getName()
         << " to heal tower " << targetTower << " of " << current.getName()
         << endl;
    current.playCard(chosen, *target);
  } else if (cardType == "multipleAtk") {
    cout << current.getName() << " used " << chosen->getName()
         << " to all towers of " << opponent.getName() << endl;

    Tower* targets = opponent.getTowers();
    static_cast<MultipleAtkCard*>(chosen)->applyAttack(targets, 3);
  } else {
    cout << "Unknown card type. Skipping turn." << endl;
  }
}

void GameManager::checkGameStatus() {
  if (player1.isDefeated() || player2.isDefeated()) {
    gameOver = true;
  }
}

void GameManager::switchTurn() {
  if (currentPlayer == &player1) {
    currentPlayer = &player2;
  } else {
    currentPlayer = &player1;
  }
}

void GameManager::updateTimer() {
  using namespace std::chrono;

  auto now = steady_clock::now();
  int elapsed = duration_cast<seconds>(now - startTime).count();

  if (elapsed >= timeLimit) {
    cout << "Time's Up!" << endl;
    gameOver = true;
  }
}

void GameManager::endGame() {
  cout << endl << "Game Over" << endl;

  int p1Tower = 0;
  int p2Tower = 0;

  for (int i = 0; i < 3; i++) {
    if (!player1.getTowers()[i].isDestroyed()) p1Tower++;
    if (!player2.getTowers()[i].isDestroyed()) p2Tower++;
  }

  if (p1Tower > p2Tower) {
    cout << player1.getName() << " wins!" << endl;
  } else if (p2Tower > p1Tower) {
    cout << player2.getName() << " wins!" << endl;
  } else {
    cout << "It's a draw!" << endl;
  }
}