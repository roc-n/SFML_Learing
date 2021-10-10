#include <iostream>
#include <yaml-cpp/emittermanip.h>
#include <yaml-cpp/yaml.h>

int main() {
  YAML::Emitter out;

  // out << "Hello,World!";

  // out << YAML::BeginSeq;
  // out << "eggs";
  // out << "bread";
  // out << "milk";
  // out << YAML::EndSeq;

  // out << YAML::BeginMap;
  // out << YAML::Key << "name";
  // out << YAML::Value << "jojo";
  // out << YAML::Key << "position";
  // out << YAML::Value << "NingBo";
  // out << YAML::Key << "children";
  // out << YAML::Value << YAML::BeginSeq << "josoda"
  //     << "jlr" << YAML::EndSeq;
  // out << YAML::EndMap;

  // out << YAML::BeginMap;
  // out << YAML::Key << "method";
  // out << YAML::Value << "least squares";
  // out << YAML::Comment("should we change this method?");
  // out << YAML::EndMap;

  std::vector<int> squares;
  squares.push_back(1);
  squares.push_back(4);
  squares.push_back(9);
  squares.push_back(16);

  std::map<std::string, int> ages;
  ages["Daniel"] = 26;
  ages["Jesse"] = 24;

  out << YAML::BeginSeq;
  out << YAML::Flow << squares;
  out << ages;
  out << YAML::EndSeq;

  std::cout << "Here's the output YAML:\n" << out.c_str() << "\n";
  return 0;
}