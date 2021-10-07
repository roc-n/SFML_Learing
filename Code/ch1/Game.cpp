#include "Game.hpp"
#include <iostream>
const float Game::playSpeed = 150.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
    : mWindow(sf::VideoMode(1280, 640), "SFML Application"), mPlayer(),
      mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false),
      mIsMovingUp(false) {
  if (!mTexture.loadFromFile("Textures/Eagle.png")) {
    std::cout << "Error,can't load the file." << std::endl;
  }
  mPlayer.setTexture(mTexture);
  mPlayer.setPosition(100.f, 100.f);
}

void Game::run() {
  sf::Clock clock;
  //固定每一帧的时间
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (mWindow.isOpen()) {
    processEvents();
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      update(TimePerFrame);
    }
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
  mPlayer.move(movement * deltaTime.asSeconds()); //路程=速度*时间
}

void Game::render() {
  mWindow.clear();
  mWindow.draw(mPlayer);
  mWindow.display();
}