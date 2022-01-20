#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
public:

	void ChangeFirstName(int year, const string& first_name) {
	 first_names[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
	  last_names[year] = last_name;
  }

  string GetFullName(int year) {
	  string current_first_name = GetActualName(first_names, year);
	  string current_last_name = GetActualName(last_names, year);

	  if (current_first_name.empty() && current_last_name.empty())
	  {
		  return "Incognito";
	  }
	  else if (current_last_name.empty())
	  {
		  return current_first_name + " with unknown last name";
	  }
	  else if (current_first_name.empty())
	  {
		  return current_last_name + " with unknown first name";
	  }
	  else
	  {
		  return current_first_name + " " + current_last_name;
	  }
  }

  string GetFullNameWithHistory(int year) {
	  string res = "";
	  return res;
  }

private:
  map <int, string> first_names;
  map <int, string> last_names;

  string GetActualName(const map<int, string>& names, int year)
  {
	  string name = "";

	  for (const auto& [key, value] : names)
	  {
		  if (key <= year)
		  {
			  name = value;
		  }
		  else
		  {
			  break;
		  }
	  }
	  return name;
  }

  vector <string> GetNamesHistory(const map<int, string>& names, int year)
  {
	vector <string> history;

	for (const auto& [key, value] : names)
	{
		if (key <= year)
		{
			history.push_back(value);
		}
		else
		{
			break;
		}
	}
	return history;
  }
};


int main()
{
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");

	cout << person.GetFullName(1940) << endl;
	return 0;
}
