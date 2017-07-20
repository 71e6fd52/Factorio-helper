#include <factorio/mod-info.hpp>

int main()
try
{
  std::string mod;
  std::getline(std::cin, mod);
  factorio::mod::info a;
  a.read_name_fast(mod);
}
catch(...)
{
  return 1;
}
