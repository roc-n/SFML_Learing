#include <iostream>
#include <string>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

int main() {

  YAML::Node config = YAML::LoadFile("test.yaml");

  float EagleHP = config["AircraftData"]["Eagle"]["fireInterval"].as<float>();
  std::cout << "The Eagle HP is " << EagleHP << std::endl;

  // YAML::Node node = YAML::Load(seq);
  std::cout << config["AircraftData"]["Raptor"]["directions"].size()
            << std::endl;

  // if (config["category"]) {
  //   std::cout << "category exist and it's "
  //             << config["category"].as<std::string>() << std::endl;
  // } else {
  //   std::cout << "Not exist category!" << std::endl;
  // }

  // if (node.IsSequence()) {
  //   std::cout << "It's just a sequence" << std::endl;
  // } else {
  //   std::cout << "It's not a sequence" << std::endl;
  // }

  //   if (config["yugi"].IsMap()) {
  //     std::cout << "yugi is a map" << std::endl;
  //   } else {
  //     std::cout << "yugi is not a map!" << std::endl;
  //   }
  return 0;
}