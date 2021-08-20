#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

template <typename T1, typename T2>
void print_map(const map <T1, T2>& m)
{
	for (const auto& [key, value] : m)
	{
		cout << key << ": " << value << endl;
	}
}

template <typename T3>
void print_vector(const vector <T3>& vtr)
{
	for (const auto& v : vtr)
	{
		cout << v << endl;
	}
	cout << endl;
}

map <char, int> build_char_counters(const string& word)
{
	map <char, int> char_counters;

	for (auto c : word)
	{
		++char_counters[c];
	}
	return char_counters;
}

int main()
{
	int pairs_count;
	cin >> pairs_count;

	string first_word;
	string second_word;
	map <char, int> map_first_word;
	map <char, int> map_second_word;
	vector <string> output;

	for (int i = 0; i < pairs_count; ++i)
	{
		cin >> first_word;
		cin >> second_word;

		map_first_word = build_char_counters(first_word);
		map_second_word = build_char_counters(second_word);

		if (map_first_word == map_second_word)
		{
			output.push_back("YES");
		}
		else
		{
			output.push_back("NO");
		}
	}

	print_vector(output);
	return 0;
}
