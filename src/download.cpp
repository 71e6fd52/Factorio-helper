#include <yaml-cpp/yaml.h>
#include <factorio/mod-info.hpp>
#include <map>

int main()
{
	using namespace std;
	YAML::Node node = YAML::Load(std::cin);
	for (const auto & i : node)
	{
		auto github = i.second["github"].as<string>();
		if (github == "")
		{
			factorio::mod::info mod;
			mod.read_url(i.second["URL"].as<string>());
			cout << "file" << endl << mod.download_url() << endl << mod.name() + "_" + mod.version() << endl;
		}
		else
		{
			factorio::mod::info mod;
			mod.read_url(i.second["URL"].as<string>());
			cout << "git" << endl << github << endl << mod.name() + "_" + mod.version() << endl;
		}
	}
}
