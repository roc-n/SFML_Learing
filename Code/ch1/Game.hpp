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
  static const sf::Time TimePerFrame;

  sf::RenderWindow mWindow;
  sf::Sprite mPlayer;
  // sf::Font mFont;
  sf::Texture mTexture;
  bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
};
#endif