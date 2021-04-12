#include <Entity.hpp>

class Aircraft : Entity {
public:
  enum class Type { Eagle, Raptor };

public:
  explicit Aircraft(Type type);

private:
  Type mType;
};