#include "ResourceHolder.hpp"
#include <iostream>
using namespace std;
int main() {
  TextureHolder textures;
  TextureHolder *ptr = new TextureHolder;
  textures.load(Textures::ID::Airplane, "Media/Textures/Airplane.png");
  sf::Sprite playerPlane;

  playerPlane.setTexture(textures.get(Textures::ID::Airplane));
  return 0;
}
