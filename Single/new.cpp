#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Vector2.hpp>

#include <iostream>
int main() {
  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");

  sf::RectangleShape shape(sf::Vector2f(100, 100));
  sf::CircleShape circle(50.f);
  sf::CircleShape c(50.f);

  shape.setOrigin(50, 50);
  circle.setOrigin(50.f, 50.f);
  c.setOrigin(50, 50);

  shape.setFillColor(sf::Color::Green);
  circle.setFillColor(sf::Color::Cyan);

  shape.setPosition(300, 300);
  circle.setPosition(300, 300);
  std::cout << circle.getOrigin().x << circle.getOrigin().y << std::endl;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(shape);
    window.draw(circle);

    sf::RenderStates state;
    state.transform = shape.getTransform();
    window.draw(c, state);

    window.display();
  }

  return 0;
}