#include <factorio/mod-info.hpp>

#include <fstream>
#include <iterator>
#include <unordered_set>
#include <yaml-cpp/yaml.h>

int main()
{
  std::ifstream in3("/proc/self/fd/3");
  std::unordered_set<std::string> nongit{std::istream_iterator<std::string>(in3), std::istream_iterator<std::string>()};
  YAML::Node node = YAML::Load(std::cin);
  for (const auto & i : node) {
    factorio::mod::info mod;
    mod.read_name_fast(i.first.as<std::string>());
    if ((nongit.erase(mod.name()) != 0u) || mod.github_path() == "") {
      mod.read_url(mod.mod_page());
      std::cout << "file" << std::endl << mod.download_url() << std::endl << mod.name() << std::endl;
    } else {
      std::cout << "git" << std::endl << mod.github_path() << std::endl << mod.name() << std::endl;
    }
  }
}
