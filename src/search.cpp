#include <factorio/mod-info.hpp>

int main()
{
	using namespace std;
	string name;
	factorio::mod::info mod;
	while(true)
	{
		cerr << "Mod name: ";
		if(!getline(cin, name))
			break;
		mod.search(name);
		cout << "    Name: " << mod.name() << endl
			<< "    Title: " << mod.title() << endl
			<< "    Licesne: " << mod.license_name() << endl
			<< "    " << mod.summary() << endl;
	}
}
