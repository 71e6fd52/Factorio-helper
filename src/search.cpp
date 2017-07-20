#include <factorio/mod-info.hpp>

int main()
{
  std::string name;
  factorio::mod::info mod;
  while(true) {
    std::cerr << "Mod name: ";
    if(!getline(std::cin, name)) break;
    mod.search(name);
    std::cout << "    Name: " << mod.name() << std::endl
      << "    Title: " << mod.title() << std::endl
      << "    Licesne: " << mod.license_name() << std::endl
      << "    " << mod.summary() << std::endl;
  }
}
