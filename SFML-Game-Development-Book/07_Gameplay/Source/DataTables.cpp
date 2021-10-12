#include <Book/Aircraft.hpp>
#include <Book/DataTables.hpp>
#include <Book/Pickup.hpp>
#include <Book/Projectile.hpp>
#include <functional>

#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>
// For std::bind() placeholders _1, _2, ...
using namespace std::placeholders;

std::vector<AircraftData> initializeAircraftData() {
  YAML::Node config = YAML::LoadFile("./other/config.yaml");

  std::vector<AircraftData> data(Aircraft::TypeCount);

  data[Aircraft::Eagle].hitpoints =
      config["Aircraft"]["Eagle"]["hitpoints"].as<int>();
  data[Aircraft::Eagle].speed =
      config["Aircraft"]["Eagle"]["speed"].as<float>();
  data[Aircraft::Eagle].fireInterval =
      sf::seconds(config["Aircraft"]["Eagle"]["fireInterval"].as<int>());
  data[Aircraft::Eagle].texture = Textures::Eagle;

  data[Aircraft::Raptor].hitpoints =
      config["Aircraft"]["Raptor"]["hitpoints"].as<int>();
  data[Aircraft::Raptor].speed =
      config["Aircraft"]["Raptor"]["speed"].as<float>();
  data[Aircraft::Raptor].texture = Textures::Raptor;
  for (int i = 0; i < config["Aircraft"]["Raptor"]["directions"].size(); ++i) {
    data[Aircraft::Raptor].directions.push_back(Direction(
        config["Aircraft"]["Raptor"]["directions"][i][0].as<float>(),
        config["Aircraft"]["Raptor"]["directions"][i][1].as<float>()));
  }
  data[Aircraft::Raptor].fireInterval = sf::Time::Zero;

  data[Aircraft::Avenger].hitpoints =
      config["Aircraft"]["Avenger"]["hitpoints"].as<int>();
  data[Aircraft::Avenger].speed =
      config["Aircraft"]["Avenger"]["hitpoints"].as<float>();
  data[Aircraft::Avenger].texture = Textures::Avenger;
  for (int i = 0; i < config["Aircraft"]["Avenger"]["directions"].size(); ++i) {
    data[Aircraft::Avenger].directions.push_back(Direction(
        config["Aircraft"]["Avenger"]["directions"][i][0].as<float>(),
        config["Aircraft"]["Avenger"]["directions"][i][1].as<float>()));
  }
  data[Aircraft::Avenger].fireInterval =
      sf::seconds(config["Aircraft"]["Avenger"]["fireInterval"].as<float>());

  return data;
}

std::vector<ProjectileData> initializeProjectileData() {
  YAML::Node config = YAML::LoadFile("./other/config.yaml");

  std::vector<ProjectileData> data(Projectile::TypeCount);

  data[Projectile::AlliedBullet].damage =
      config["Projectile"]["AlliedBullet"]["damage"].as<int>();
  data[Projectile::AlliedBullet].speed =
      config["Projectile"]["AlliedBullet"]["speed"].as<float>();
  data[Projectile::AlliedBullet].texture = Textures::Bullet;

  data[Projectile::EnemyBullet].damage =
      config["Projectile"]["EnemyBullet"]["damage"].as<int>();
  data[Projectile::EnemyBullet].speed =
      config["Projectile"]["EnemyBullet"]["speed"].as<float>();
  data[Projectile::EnemyBullet].texture = Textures::Bullet;

  data[Projectile::Missile].damage =
      config["Projectile"]["Missile"]["damage"].as<int>();
  data[Projectile::Missile].speed =
      config["Projectile"]["Missile"]["speed"].as<float>();
  data[Projectile::Missile].texture = Textures::Missile;

  return data;
}

std::vector<PickupData> initializePickupData() {
  YAML::Node config = YAML::LoadFile("./other/config.yaml");

  std::vector<PickupData> data(Pickup::TypeCount);

  data[Pickup::HealthRefill].texture = Textures::HealthRefill;
  data[Pickup::HealthRefill].action = [](Aircraft &a) { a.repair(25); };

  data[Pickup::MissileRefill].texture = Textures::MissileRefill;
  data[Pickup::MissileRefill].action =
      std::bind(&Aircraft::collectMissiles, _1, 3);

  data[Pickup::FireSpread].texture = Textures::FireSpread;
  data[Pickup::FireSpread].action = std::bind(&Aircraft::increaseSpread, _1);

  data[Pickup::FireRate].texture = Textures::FireRate;
  data[Pickup::FireRate].action = std::bind(&Aircraft::increaseFireRate, _1);

  return data;
}