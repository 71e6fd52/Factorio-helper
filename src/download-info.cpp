#include <yaml-cpp/yaml.h>
#include <factorio/mod-info.hpp>
#include <fstream>
#include <unordered_set>
#include <iterator>

int main()
{
	using namespace std;
	std::ifstream in3("/proc/self/fd/3");
	unordered_set<string> nongit{istream_iterator<string>(in3), istream_iterator<string>()};
	YAML::Node node = YAML::Load(std::cin);
	for (const auto & i : node)
	{
		factorio::mod::info mod;
		mod.read_name_fast(i.first.as<string>());
		if (nongit.erase(mod.name()) || mod.github_path() == "")
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
