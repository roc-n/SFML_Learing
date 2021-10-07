#include <SFML/Graphics.hpp>
#include <iostream>
int main(void) {
  sf::RenderWindow window(sf::VideoMode(1280, 640), "input window");
  sf::CircleShape circle(200.0f);
  circle.setOrigin(circle.getGlobalBounds().width / 2.f,
                   circle.getGlobalBounds().height / 2.f);
  circle.setFillColor(sf::Color::Blue);
  circle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
  circle.setOutlineThickness(20.f);
  //   circle.setOutlineColor(sf::Color(250, 150, 100));
  int r, g, b;
  r = g = b = 0;

  bool isSecond = false;
  bool isThird = false;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    circle.setOutlineColor(sf::Color(r, g, b));
    if (!isSecond && r == 255) {
      r = 0;
      isSecond = true;
    } else if (!isThird && g == 255) {
      g = 0;
      isSecond = false;
      isThird = true;
    } else if (b == 255) {
      b = 0;
      isThird = false;
    }

    if (isSecond) {
      g++;
    } else if (isThird) {
      b++;
    } else {
      r++;
    }

    window.clear();
    window.draw(circle);
    window.display();
  }
  return 0;
}