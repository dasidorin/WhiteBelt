#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T1>
void PrintVector(const vector <T1>& vtr)
{
	for (const auto& v : vtr)
	{
		cout << v << " ";
	}
}


string StringToLower(const string& str)
{
	string res_str = str;

	for (auto& s : res_str)
	{
		if (s >= 'A' && s <= 'Z')
		{
			s = tolower(s);
		}
	}
	return res_str;
}

int main()
{
	int n = 0;
	cin >> n;

	vector <string> strs (n);
	for (auto& s : strs)
	{
		cin >> s;
	}

	sort(begin(strs), end(strs), [](const string& s1, const string& s2)
	{
		return StringToLower(s1) < StringToLower(s2);
	});

	PrintVector(strs);
	return 0;
}
