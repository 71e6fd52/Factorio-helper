#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

int main()
{
	using namespace std;
	using namespace YAML;
	std::ifstream yml("/proc/self/fd/3");
	Node node = Load(yml);
	string modname;
	while (getline(std::cin, modname))
		node[modname] = true;
	YAML::Emitter em;
	em << node;
	cout << em.c_str() << endl;
}
