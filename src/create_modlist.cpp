#include <iostream>
#include <yaml-cpp/yaml.h>

int main()
{
  using std::cout;
  YAML::Node node = YAML::Load(std::cin);
  cout << R"({
  "mods": [
    {
      "name": "base",
      "enabled": true
    },
)";
    for (const auto & i : node) {
      cout << R"(    {
      "name": ")" << i.first << R"(",)" << R"(
      "enabled": )" << i.second << R"(
    },
)";
    }
  cout << R"(  ]
}
)";
}
