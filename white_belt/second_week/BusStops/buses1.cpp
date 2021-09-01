#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct s_operations
{
	string operation;
	string bus;
	string current_stop;
	int stop_count = 0;
	vector <string> stops;
};

template <typename T1>
void print_vector(const vector<T1>& vtr)
{
	for (const auto& v : vtr)
	{
		cout << v << " ";
	}
}

void print_map_with_vector(const map <string, vector <string>>& mp)
{
	for (auto [key, value] : mp)
	{
		cout << key << " : ";
		print_vector(value);
		cout << endl;
	}
}

void	print_s_operations(const s_operations& operations)
{
	cout << "OPERATION: " << operations.operation << endl;
	if (!operations.bus.empty())
	{
		cout << "BUS: " << operations.bus << endl;
	}
	if (operations.stop_count != 0)
	{
		cout << "STOP COUNT: " << operations.stop_count << endl;
	}
	if (!operations.stops.empty())
	{
		cout << "STOPS: ";
		print_vector(operations.stops);
		cout << endl;
	}
	if (!operations.current_stop.empty())
	{
		cout << "CURRENT STOP: " << operations.current_stop << endl;
	}
	cout << endl;
}


vector <s_operations> parse_operations(const int& count_operations)
{
	vector <s_operations> operations(count_operations);
	string current_stop;

	for (int i = 0; i < count_operations; ++i)
	{
		cin >> operations[i].operation;
		if (operations[i].operation == "NEW_BUS")
		{
			cin >> operations[i].bus;
			cin >> operations[i].stop_count;
			for (int s = 0; s < operations[i].stop_count; ++s)
			{
				cin >> current_stop;
				operations[i].stops.push_back(current_stop);
			}
		}
		if (operations[i].operation == "BUSES_FOR_STOP")
		{
			cin >> operations[i].current_stop;
		}
		if (operations[i].operation == "STOPS_FOR_BUS")
		{
			cin >> operations[i].bus;
		}
	}
	return operations;
}

bool execute_operations(const vector <s_operations>& operations, map <string, vector <string>>& buses, map <string, vector <string>>& stops)
{
	for (int i = 0; i < (int)operations.size(); i++)
	{
		if (operations[i].operation == "NEW_BUS")
		{
				buses[operations[i].bus] = operations[i].stops;
				for (auto& s : operations[i].stops)
				{
					stops[s].push_back(operations[i].bus);
				}
		}
		if (operations[i].operation == "BUSES_FOR_STOP")
		{
			if (stops.count(operations[i].current_stop) == 0)
			{
				cout << "No stop" << endl;
			}
			else
			{
				print_vector(stops[operations[i].current_stop]);
				cout << endl;
			}
		}
		if (operations[i].operation == "STOPS_FOR_BUS")
		{
			if (buses.count(operations[i].bus) == 0)
			{
				cout << "No bus" << endl;
			}
			else
			{
				for (auto b : buses[operations[i].bus])
				{
					cout << "Stop " << b << ": ";
					if (stops.count(b) != 0)
					{
						for (auto& s : stops[b])
						{
							if (s != operations[i].bus)
							{
								cout << s << " ";
							}
						}
						if (stops[b].size() == 1 && stops[b][0] == operations[i].bus)
						{
							cout << "no interchange";
						}
					}
					cout << endl;
				}
			}
		}
		if (operations[i].operation == "ALL_BUSES")
		{
			if (buses.size() == 0)
			{
				cout << "No buses" << endl;
			}
			else
			{
				for (auto [key, value] : buses)
				{
					cout << "Bus " << key << ": ";
					print_vector(value);
					cout << endl;
				}
			}
		}
	}
	return true;
}

int main()
{
	int	count_operation;
	cin >> count_operation;

	vector <s_operations> operations = parse_operations(count_operation);

	map <string, vector<string>> buses;
	map <string, vector<string>> stops;
	execute_operations(operations, buses, stops);
	return 0;
}
