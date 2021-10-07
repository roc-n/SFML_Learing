#include "ResourceHolder.hpp"

sf::Texture &TextureHolder::get(Textures::ID id) {
  auto found = mTextureMap.find(id);
  assert(found != mTextureMap.end());
  return *found->second;
}
