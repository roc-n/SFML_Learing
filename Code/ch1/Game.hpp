#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics.hpp>

class Game {
public:
  void run();
  Game();

private:
  void processEvents();
  void update(sf::Time);
  void render();
  void handlePLayerInput(sf::Keyboard::Key key, bool isPressed);

private:
  static const float playSpeed;
  sf::RenderWindow mWindow;
  sf::CircleShape mPlayer;
  bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
};
#endif