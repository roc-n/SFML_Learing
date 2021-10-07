#include "Game.hpp"
#include <iostream>
using namespace std;
int main() {
  Game game;
  game.run();
  for (int i = 0; i < 10; ++i) {
    cout << "You're really special" << endl;
  }

  return 0;
}