#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int count_of_strings;

	cin >> count_of_strings;
	set <string> strs;

	for (int i = 0; i < count_of_strings; ++i)
	{
		string current_string;
		cin >> current_string;
		strs.insert(current_string);
	}
	cout << strs.size() << endl;
	return 0;
}
