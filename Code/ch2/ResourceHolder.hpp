#ifndef _RESOURCEHOLDER_HPP_
#define _RESOURCEHOLDER_HPP_
#include <SFML/Graphics.hpp>
#include <cassert>
#include <map>
#include <memory>

namespace Textures {
enum class ID { Landscape, Airplane, Missle };
}

template <typename Resource, typename Identifier> class ResourceHolder {
private:
  std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

public:
  void load(Identifier id, const std::string &filename);
  Resource &get(Textures::ID id);
  const Resource &get(Textures::ID id) const;
};

#include "ResourceHolder.inl"
#endif