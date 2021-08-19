#include <iostream>
#include <string>
#include <vector>

#define ERR_ADD_TASK_TO_DAY 1
#define ERR_DUMP_TASK_ASSIGNED_TO_DAY 2


using namespace std;

struct s_parsed_data {
	string operation;
	int day_number;
	string task;
};

template <typename T>
void print_vector(const vector <T>& vtr, bool is_endl)
{
	for (auto v : vtr)
	{
		cout << v;
	}

	if (is_endl == true)
	{
		cout << endl;
	}
}

bool add_task_to_day(vector <vector <string>>& affairs, int day_number, string task)
{
	if (day_number > (int)affairs.size())
	{
		return false;
	}
	affairs[day_number - 1].push_back(task);
	return true;
}

bool dump_task_assigned_to_day(const vector <vector <string>> affairs, int day_number)
{
	if (day_number > (int)affairs.size())
	{
		return false;
	}

	cout << affairs[day_number - 1].size() << " ";
	for (auto aa : affairs[day_number - 1])
	{
		cout << aa << " ";
	}
	cout << endl;
	return true;
}

vector <vector <string>> move_to_next_mounth(vector <vector <string>> affairs, int *mounth_index, const vector <int>& mounth_days)
{
	vector <vector <string>> new_affairs;

	*mounth_index += 1;
	if (*mounth_index > 11)
	{
		*mounth_index = 0;
	}

	if (mounth_days[*mounth_index] < (int)affairs.size())
	{
		int current = mounth_days[*mounth_index];
		for (int i = current; i < (int)affairs.size(); ++i)
		{
			for (auto aa : affairs[i])
			{
				affairs[current - 1].push_back(aa);
			}
		}
	}
	affairs.resize(mounth_days[*mounth_index]);
	new_affairs.insert(end(new_affairs), begin(affairs), end(affairs));
	return new_affairs;
}


int main()
{
	int count_operation;
	cin >> count_operation;

	vector<s_parsed_data> parsed_data(count_operation);

	for (int i = 0; i < count_operation; ++i)
	{
		cin >> parsed_data[i].operation;
		if (parsed_data[i].operation == "ADD")
		{
			cin >> parsed_data[i].day_number;
			cin >> parsed_data[i].task;
		}
		else if (parsed_data[i].operation == "DUMP")
		{
			cin >> parsed_data[i].day_number;
			parsed_data[i].task = "";
		}
		else if (parsed_data[i].operation == "NEXT")
		{
			parsed_data[i].day_number = 0;
			parsed_data[i].task = "";
		}
	}

	int mounth_index = 0;
	vector <int> mounth_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector <vector <string>> affairs (mounth_days[mounth_index]);

	for (int j = 0; j < count_operation; ++j)
	{
		if (parsed_data[j].operation == "ADD")
		{
			if (!add_task_to_day(affairs, parsed_data[j].day_number, parsed_data[j].task))
			{
				return ERR_ADD_TASK_TO_DAY;
			}
		}
		else if (parsed_data[j].operation == "DUMP")
		{
			if (!dump_task_assigned_to_day(affairs, parsed_data[j].day_number))
			{
				return ERR_DUMP_TASK_ASSIGNED_TO_DAY;
			}
		}
		else if (parsed_data[j].operation == "NEXT")
		{
			affairs = move_to_next_mounth(affairs, &mounth_index, mounth_days);
		}
	}
	return 0;
}
