#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

struct s_operations
{
	string action;
	string word1;
	string word2;
};

vector <s_operations> parse_actions(int count_action)
{
	vector <s_operations> actions(count_action);

	for (int i = 0; i < count_action; ++i)
	{
		cin >> actions[i].action;
		if (actions[i].action == "ADD" || actions[i].action == "CHECK")
		{
			cin >> actions[i].word1 >> actions[i].word2;
		}
		else if (actions[i].action == "COUNT")
		{
			cin >> actions[i].word1;
		}
	}
	return actions;
}

void execute_actions(const vector <s_operations>& actions)
{
	set <set <string>> words;

	for (int i = 0; i < (int)actions.size(); ++i)
	{
		if (actions[i].action == "ADD" || actions[i].action == "CHECK")
		{
			set <string> current_words;
			current_words.insert(actions[i].word1);
			current_words.insert(actions[i].word2);

			if (actions[i].action == "ADD")
			{
				words.insert(current_words);
			}
			else
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
		else if (actions[i].action == "COUNT")
		{
			int count = 0;
			for (auto w : words)
			{
				if (w.count(actions[i].word1) > 0)
				{
					count++;
				}
			}
			cout << count << endl;
		}
	}
}

int main()
{
	int count_action;
	cin >> count_action;

	vector <s_operations> actions = parse_actions(count_action);
	execute_actions(actions);
	return 0;
}
