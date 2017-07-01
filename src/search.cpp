#include <factorio/mod-info.hpp>

int main()
{
	using namespace std;
	cout << "Mod name: ";
	string name;
	cin >> name;
	factorio::mod::info mod;
	mod.search(name);
	cout << "Name: " << mod.name() << endl
		<< "Title: " << mod.title() << endl
		<< "Licesne: " << mod.license_name() << endl
		<< mod.summary() << endl;
}
