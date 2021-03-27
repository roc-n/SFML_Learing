#include "Game.hpp"

const float Game::playSpeed = 100.f;

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer() {
  mPlayer.setRadius(40.f);
  mPlayer.setPosition(100.f, 100.f);
  mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run() {
  sf::Clock clock;
  while (mWindow.isOpen()) {
    sf::Time deltaTime = clock.restart();
    processEvents();
    update(deltaTime);
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (mWindow.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::KeyPressed:
      handlePLayerInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      handlePLayerInput(event.key.code, false);
      break;
    case sf::Event::Closed:
      mWindow.close();
      break;
    }
  }
}

void Game::handlePLayerInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::W) {
    mIsMovingUp = isPressed;
  } else if (key == sf::Keyboard::S) {
    mIsMovingDown = isPressed;
  } else if (key == sf::Keyboard::A) {
    mIsMovingLeft = isPressed;
  } else if (key == sf::Keyboard::D) {
    mIsMovingRight = isPressed;
  }
}

void Game::update(sf::Time deltaTime) {
  sf::Vector2f movement(0.f, 0.f);
  if (mIsMovingUp) {
    movement.y -= playSpeed;
  }
  if (mIsMovingDown) {
    movement.y += playSpeed;
  }
  if (mIsMovingLeft) {
    movement.x -= playSpeed;
  }
  if (mIsMovingRight) {
    movement.x += playSpeed;
  }
  mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render() {
  mWindow.clear();
  mWindow.draw(mPlayer);
  mWindow.display();
}