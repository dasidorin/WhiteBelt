#include <iostream>
#include <string>
#include <map>


using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name)
	{
		data[year].first_name = first_name;
	}
	void ChangeLastName(int year, const string& last_name)
	{
		data[year].last_name = last_name;
	}
	string GetFullName(int year)
	{
		string res_last_name = "";
		string res_first_name = "";

		for (auto& [key, value] : data)
		{
			if (key > year)
			{
				break;
			}
			if (!value.first_name.empty())
			{
				res_first_name = value.first_name;
			}
			if (!value.last_name.empty())
			{
				res_last_name = value.last_name;
			}
			if (key == year)
			{
				break;
			}
		}

		if (res_first_name.empty() && res_last_name.empty())
		{
			return "Incognito";
		}
		else if (res_first_name.empty() && !res_last_name.empty())
		{
			return res_last_name + " with unknown first name";
		}
		else if (!res_first_name.empty() && res_last_name.empty())
		{
			return res_first_name + " with unknown last name";
		}
		else
		{
			return res_first_name + " " + res_last_name;
		}
	}
private:
	struct	s_names {
		string last_name = "";
		string first_name = "";
	};
	map <int, s_names> data;
};

