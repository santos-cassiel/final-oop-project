// #include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
#include <iostream>

#include "../include/GameManager.h"

using namespace std;

int main() {
  while (true) {
    cout << "*** Tower Game ***" << endl;
    cout << "Objective: Defeat all enemy towers within 3 minutes." << endl
         << endl;
    cout << "There are 3 types of moves: " << endl;
    cout << " - Single Tower Attack (Fireball, Cannon Shot, "
            "Lightning Strike)"
         << endl;
    cout << " - Muliple Tower Attack (Arrow Volley, Blazing Barrage)" << endl;
    cout << " - Single Tower Heal (Repair Kit)" << endl << endl;
    cout << "If timer exceeds limit, and you did not destroy all opponent "
            "towers, the game"
         << endl;
    cout << "will check who destroyed most towers. It will end in a draw if "
            "both "
            "players have"
         << endl;
    cout << "the same amount of towers standing. Good luck." << endl << endl;

    cout << "Press Enter to continue";

    std::string temp;

    while (true) {
      std::getline(std::cin, temp);
      if (temp.empty()) {
        break;
      } else {
        cout << "Invalid input. Press Enter only";
      }
    }

    break;
  }

  system("clear");

  string name1, name2;

  cout << "Enter Player 1 name: ";
  cin >> name1;

  cout << "Enter Player 2 name: ";
  cin >> name2;

  GameManager game(name1, name2);

  game.startGame();

  // sf::Window window(sf::VideoMode({1500, 900}), "My window");

  // while (window.isOpen()) {
  //   sf::Event event;
  //   while (window.pollEvent(event)) {
  //     if (event.type == sf::Event::Closed) {
  //       window.close();
  //     }
  //   }
  // }
}