// #include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
#include <iostream>

#include "../include/GameManager.h"

using namespace std;

int main() {
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