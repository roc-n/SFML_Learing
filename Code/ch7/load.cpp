#include <iostream>
#include <string>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

int main() {
  YAML::Node config = YAML::LoadFile("test.yaml");
  YAML::Node node = YAML::Load("[1,2,3,4,5]");

  if (config["category"]) {
    std::cout << "category exist and it's "
              << config["category"].as<std::string>() << std::endl;
  } else {
    std::cout << "Not exist category!" << std::endl;
  }

  if (node.IsSequence()) {
    std::cout << "It's just a sequence" << std::endl;
  } else {
    std::cout << "It's not a sequence" << std::endl;
  }

  //   if (config["yugi"].IsMap()) {
  //     std::cout << "yugi is a map" << std::endl;
  //   } else {
  //     std::cout << "yugi is not a map!" << std::endl;
  //   }
  return 0;
}