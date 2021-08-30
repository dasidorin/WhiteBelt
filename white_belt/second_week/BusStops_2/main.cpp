#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct s_operations
{
	int				stops_count = 0;
	vector <string>	stops;
};

template <typename T1>
void print_vector(const vector <T1>& vtr)
{
	for (const auto& v : vtr)
	{
		cout << v << " ";
	}
}

void print_vector_struct(const vector <s_operations>& operations)
{
	for (int i = 0; i < (int)operations.size(); ++i)
	{
		if (operations[i].stops_count != 0)
		{
			cout << "COUNT: " << operations[i].stops_count << endl;
		}
		if (operations[i].stops.size() != 0)
		{
			cout << "STOPS: ";
			print_vector(operations[i].stops);
			cout << endl;
		}
	}
}

vector <s_operations> parse_operations(const int& count_operations)
{
	vector <s_operations> operations (count_operations);
	string current_stop;

	for (int i = 0; i < count_operations; ++i)
	{
		cin >> operations[i].stops_count;
		for (int j = 0; j < operations[i].stops_count; ++j)
		{
			cin >> current_stop;
			operations[i].stops.push_back(current_stop);
		}
	}
	return operations;
}

bool is_this_value(const map <int, vector <string>>& buses, vector <string> current_stop)
{
	for (const auto& [key, value] : buses)
	{
		if (value == current_stop)
		{
			cout << "Already exists for " << key << endl;
			return true;
		}
	}
	return false;
}

void execute_operations(const vector <s_operations>& operations)
{
	int operations_size = (int)operations.size();
	map <int, vector <string>> buses;

	for (int i = 0; i < operations_size; ++i)
	{
		if (!is_this_value(buses, operations[i].stops))
		{
			int buses_size = buses.size();
			cout << "New bus " << buses_size + 1 << endl;
			buses[buses_size + 1] = operations[i].stops;
		}
	}
}

int main()
{
	int count_operations;
	cin >> count_operations;

	vector <s_operations> operations = parse_operations(count_operations);
	execute_operations(operations);
	return 0;
}
