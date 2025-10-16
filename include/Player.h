# include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Deck.h"
#include "Tower.h"
#include "Card.h"

using namespace std;

class Player {
private:
    string name;                            // Player's name
    int health;                                   // Set a health numbeer
    Tower tower;                                  // HP
    Deck deck;                                   
    vector<std::shared_ptr<Card>> hand;      // Player's card
    size_t maxHandSize;                      // The maximum card can be hold

public:
    // constructors
    explicit Player(const string& playerName,
                    int maxHp = 100,
                    int towerHp = 100,
                    size_t maxHand = 3);

    const std::string& getName() const;
    int  getHealth() const;
    bool isAlive() const;

    bool drawCard();                              
    bool playCard(std::size_t handIndex, Player& target);
    std::size_t handSize() const;                 
    void showHand() const;                        

    // 戰鬥相關
    void takeDamage(int amount);                   // Get attacked and reduce health
    void heal(int amount);                         // increases health
};
