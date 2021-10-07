
template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id,
                                                const std::string &filename) {
  std::unique_ptr<Resource> resource(new Resource());
  if (!resource->loadFromFile(filename)) {
    throw std::runtime_error("ResourceHolder::load - Failed to load " +
                             filename);
  }
  // std::move将一个左值转换为右值引用类型并绑定到右值引用
  auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
  assert(inserted.second);
}

template <typename Resource, typename Identifier>
const Resource &ResourceHolder<Resource, Identifier>::get(Identifier id) const {
  auto found = mResourceMap.find(id);
  assert(found != mResourceMap.end());

  return *found->second;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(
    Identifier id, std::unique_ptr<Resource> resource) {
  // Insert and check success
  auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
  assert(inserted.second);
}