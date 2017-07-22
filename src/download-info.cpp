#include <factorio/mod-info.hpp>

#include <DA/exception.hpp>
#include <fstream>
#include <iterator>
#include <unordered_set>
#include <yaml-cpp/yaml.h>

int main()
try
{
  std::ifstream in3("/proc/self/fd/3");
  std::unordered_set<std::string> nongit{std::istream_iterator<std::string>(in3), std::istream_iterator<std::string>()};
  YAML::Node node = YAML::Load(std::cin);
  for (const auto & i : node) {
    if(!i.second.as<bool>()) continue;
    factorio::mod::info mod;
    mod.read_name_fast(i.first.as<std::string>());
    if ((nongit.erase(mod.name()) != 0u) || mod.github_path() == "") {
      mod.read_url(mod.mod_page());
      std::cout << "file" << std::endl;
      std::cout << mod.name() << std::endl;
      std::cout << mod.download_url() << std::endl;
    } else {
      std::cout << "git" << std::endl;
      std::cout << mod.name() << std::endl;
      std::cout << mod.github_path() << std::endl;
    }
  }
}
DA_MAIN_CATCH
