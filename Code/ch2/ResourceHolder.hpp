#include <SFML/Graphics.hpp>
#include <cassert>
#include <map>
#include <memory>

namespace Textures {
enum class ID { Landscape, Airplane, Missle };
}
class TextureHolder {
private:
  std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

public:
  void load(Textures::ID id, const std::string &filename);
  sf::Texture &get(Textures::ID id);
  const sf::Texture &get(Textures::ID id) const;
};