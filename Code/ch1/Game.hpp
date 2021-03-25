#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics.hpp>

class Game {
public:
  void run();
  Game();

private:
  void processEvents();
  void update();
  void render();

private:
  sf::RenderWindow mWindow;
  sf::CircleShape mPlayer;
};
#endif