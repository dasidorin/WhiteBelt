#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;


int main()
{
	int count_actions;

	cin >> count_actions;
	string action, word1, word2;
	map <string, int> word_counter;
	set <set <string>> words;
	for (int i = 0; i < count_actions; ++i)
	{
		cin >> action;
		if (action == "ADD" || action == "CHECK")
		{
			cin >> word1 >> word2;
			set <string> current_words;
			current_words.insert(word1);
			current_words.insert(word2);
			if (action == "ADD")
			{
				words.insert(current_words);
				word_counter[word1] += 1;
				word_counter[word2] += 1;
			}
			else if (action == "CHECK")
			{
				if (words.count(current_words) > 0)
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
		}
		else if (action == "COUNT")
		{
			cin >> word1;
			int cnt = 0;
			if (word_counter.count(word1) > 0)
			{
				cnt = word_counter[word1];
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
