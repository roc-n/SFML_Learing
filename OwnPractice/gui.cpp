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
  text.setOrigin(text.getLocalBounds().width,
                 text.getLocalBounds().height + 200.f);
  sf::Vector2f jojo(window.getSize().x / 2.f, window.getSize().y / 2.f);
  std::cout << text.getOrigin().x << " " << text.getOrigin().y << std::endl;

  text.setPosition(jojo);
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
    // text.rotate(1.f);
    // if (text.getRotation() > 360) {
    //   text.setRotation(0);
    // }

    window.clear();
    window.draw(text);
    // window.draw(sprite);
    window.display();
  }

  return 0;
}