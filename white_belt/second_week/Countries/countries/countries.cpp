#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool dump_countries(const map <string, string>& countries)
{
	if (countries.size() == 0)
	{
		cout << "There are no countries in the world" << endl;
		return false;
	}

	for (const auto& [country, capital] : countries)
	{
		cout << country << "/" << capital << " ";
	}
	cout << endl;
	return true;
}

bool about_country(map <string, string>& countries, const string& country)
{
	if (countries.count(country) == 0)
	{
		cout << "Country " << country << " doesn't exist" << endl;
		return false;
	}
	else
	{
		cout << "Country " << country << " has capital " << countries[country] << endl;
	}
	return true;
}

bool change_capital(map <string, string>& countries, const string& country, const string& new_capital)
{
	for (auto& [current_country, current_capital] : countries)
	{
		if (current_country == country)
		{
			if (current_capital == new_capital)
			{
				cout << "Country " << country << " hasn't changed its capital" << endl;
				return false;
			}
			else
			{
				cout << "Country " << country << " has changed its capital from " << current_capital << " to " << new_capital << endl;
				current_capital = new_capital;
				return true;
			}
		}
	}

	countries[country] = new_capital;
	cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	return true;
}

bool rename_country(map <string, string>& countries, const string& old_country_name, const string& new_country_name)
{
	if (countries.count(old_country_name) && !countries.count(new_country_name))
	{
		string swp_capital = countries[old_country_name];
		countries.erase(old_country_name);
		countries[new_country_name] = swp_capital;
		cout << "Country " << old_country_name << " with capital " << swp_capital << " has been renamed to " << new_country_name << endl;
	}
	else if (!countries.count(old_country_name) || countries.count(new_country_name) || old_country_name == new_country_name)
	{
		cout << "Incorrect rename, skip" << endl;
		return false;
	}
	return true;
}

struct s_operations {
	string operation;
	string current_country_name;
	string new_country_name;
	string current_capital;
	string new_capital;
};

void print_vector_with_structure(const vector <s_operations>& vtr)
{
	for (const auto& v : vtr)
	{
		cout << v.operation << " ";
		if (!v.current_country_name.empty())
		{
			cout << v.current_country_name << " ";
		}
		if (!v.new_country_name.empty())
		{
			cout << v.new_country_name << " ";
		}
		if (!v.current_capital.empty())
		{
			cout << v.current_capital << " ";
		}
		if (!v.new_capital.empty())
		{
			cout << v.new_capital;
		}
		cout << endl;
	}
}

vector <s_operations> parse_operations(const int& count_operation)
{
	vector <s_operations> operations(count_operation);

	for (int i = 0; i < count_operation; ++i)
	{
		cin >> operations[i].operation;
		if (operations[i].operation == "CHANGE_CAPITAL")
		{
			cin >> operations[i].current_country_name >> operations[i].new_capital;
		}
		else if (operations[i].operation == "RENAME")
		{
			cin >> operations[i].current_country_name >> operations[i].new_country_name;
		}
		else if (operations[i].operation == "ABOUT")
		{
			cin >> operations[i].current_country_name;
		}
	}
	return operations;
}

bool make_operations(vector <s_operations> operations)
{
	map <string, string> countries;

	for (size_t i = 0; i < operations.size(); ++i)
	{
		if (operations[i].operation == "CHANGE_CAPITAL")
		{
			change_capital(countries, operations[i].current_country_name, operations[i].new_capital);
		}
		if (operations[i].operation == "RENAME")
		{
			rename_country(countries, operations[i].current_country_name, operations[i].new_country_name);
		}
		if (operations[i].operation == "ABOUT")
		{
			about_country(countries, operations[i].current_country_name);
		}
		if (operations[i].operation == "DUMP")
		{
			dump_countries(countries);
		}
	}
	return true;
}

int main()
{
	int	count_operations;

	cin >> count_operations;

	vector <s_operations> operations = parse_operations(count_operations);
	make_operations(operations);
	return 0;
}
