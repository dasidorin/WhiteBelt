#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set <string> res;

	for (const auto& [key, value] : m)
	{
		res.insert(value);
	}
	return res;
}
