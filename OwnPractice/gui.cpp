#include <SFML/Graphics.hpp>
#include <iostream>
int main(void) {
  sf::RenderWindow window(sf::VideoMode(1280.f, 640.f), "gui");
  sf::Font font;
  sf::Texture texture;
  if (!texture.loadFromFile("./desert.png ")) {
    return EXIT_FAILURE;
  }
  if (!font.loadFromFile("./FiraCode-Retina.ttf")) {
    return EXIT_FAILURE;
  }
  sf::Text text("TYK", font, 40);
  sf::Sprite sprite(texture);
  text.setOrigin(640.f, 320.f);
  sf::Vector2f jojo(window.getSize().x / 2.f, window.getSize().y / 2.f);
  std::cout << text.getOrigin().x << " " << text.getOrigin().y << std::endl;

  text.setPosition(0, 0);
  std::cout << text.getPosition().x << " " << text.getPosition().y << std::endl;
  std::cout << text.getOrigin().x << " " << text.getOrigin().y << std::endl;
  text.setFillColor(sf::Color::Blue);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    if (text.getPosition().x == window.getSize().x / 2.f &&
        text.getPosition().y == window.getSize().y / 2.f) {
    } else {
      text.move(1.f, 0.5f);
    }
    window.clear();
    window.draw(text);
    // window.draw(sprite);
    window.display();
  }

  return 0;
}