#include <factorio/mod-info.hpp>

int main()
{
	std::string mod;
	std::getline(std::cin, mod);
	factorio::mod::info a;
	a.read_name_fast(mod);
}
