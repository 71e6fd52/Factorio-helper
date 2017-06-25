#include <yaml-cpp/yaml.h>
#include <factorio/mod-info.hpp>

int main()
{
	using namespace std;
	YAML::Node node = YAML::Load(std::cin);
	for (const auto & i : node)
	{
		factorio::mod::info mod;
		mod.read_name_fast(i.first.as<string>());
		if (mod.github_path() == "")
		{
			mod.read_url(mod.mod_page());
			cout << "file" << endl << mod.download_url() << endl << mod.name() << endl;
		}
		else
		{
			cout << "git" << endl << mod.github_path() << endl << mod.name() << endl;
		}
	}
}
