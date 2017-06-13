#define AVHTTP_DISABLE_THREAD
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <factorio/mod-info.hpp>
#include <yaml-cpp/yaml.h>

YAML::Emitter& operator << (YAML::Emitter& out, const factorio::mod::info & mod)
{
	using namespace YAML;
	out << Key << mod.name() << Value <<
		BeginMap << 
		Key << "URL" << Value << mod.mod_page().to_string() <<
		Key << "github" << Value << mod.github_path() << 
		EndMap;
    return out;
}

class mod_list
{
private:
	YAML::Emitter out;
public:
	mod_list()
	{
		out << YAML::BeginMap;
	}
	~mod_list()
	{
		out << YAML::EndMap;
		std::cout << out.c_str() << std::endl;
	}
	void add(std::string name)
	{
		factorio::mod::info m;
		m.read_name_fast(name);
		out << m;
	}
};

int main()
{
	using namespace std;
	using namespace factorio;
	std::unordered_set<string> name;
	string n;
	while(getline(cin, n))
		name.insert(n);
	mod_list list;
	for (const auto & i : name)
	{
		cerr << "getting " << i << endl;
		list.add(i);
	}
}
