#include "ResourceHolder.hpp"
#include <iostream>
using namespace std;
int main() {
  TextureHolder textures;
  textures.load(Textures::ID::Airplane, "Media/Textures/Airplane.png");
  textures.load(Textures::ID::Landscape, "Media/Textures/Airplane.png");
  textures.load(Textures::ID::Missle, "Media/Textures/Missle.png");
  sf::Sprite playerPlane;

  playerPlane.setTexture(textures.get(Textures::ID::Airplane));
  return 0;
}
