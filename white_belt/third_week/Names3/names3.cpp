#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person {
public:

    Person (const string& first_name, const string& last_name, const int& birthdate) {
        first_names[birthdate] = first_name;
        last_names[birthdate] = last_name;
        birth_year = birthdate;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year >= birth_year)
            first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        if (year >= birth_year)
            last_names[year] = last_name;
    }

    string GetFullName(int year) const {

        if (year < birth_year)
            return ("No person");

        string current_first_name = GetHistory(year, first_names);
        string current_last_name = GetHistory(year, last_names);

        if (current_first_name.empty() && current_last_name.empty())
            return "Incognito";
        else if (current_first_name.empty() && !current_last_name.empty())
        {
            return current_last_name + " with unknown first name";
        }
        else if (!current_first_name.empty() && current_last_name.empty())
        {
            return current_first_name + " with unknown last name";
        }
        else
        {
            return current_first_name + " " + current_last_name;
        }
    }

    string GetFullNameWithHistory(int year) const
    {

        if (year < birth_year)
            return "No person";
        string current_first_name = GetHistory(year, first_names);
        string current_last_name = GetHistory(year, last_names);

        string first_name_history = GetFullHistory(year, first_names);
        string last_name_history = GetFullHistory(year, last_names);

        if (current_first_name.empty() && current_last_name.empty())
        {
            return "Incognito";
        }
        else if (current_first_name.empty() && !current_last_name.empty())
        {
            return current_last_name + last_name_history + " with unknown first name";
        }
        else if (!current_first_name.empty() && current_last_name.empty())
        {
            return current_first_name + first_name_history + " with unknown last name";
        }
        else
        {
            string result = current_first_name;

            if (first_name_history.empty())
                result += " ";
            else
                result += first_name_history;

            result = result + current_last_name + last_name_history;
            return result;
        }
    }

private:
    map <int, string> first_names;
    map <int, string> last_names;
    int birth_year;

    string GetHistory(int year, const map <int, string>& names) const
    {
        string history = "";
        for (const auto& [key, value] : names)
        {
            if (key <= year)
                history = value;
            else
                break;
        }
        return history;
    }

    string GetFullHistory(int year, const map <int, string>& names) const
    {
        vector <string> full_history;

        for (const auto& [key, value] : names)
        {
            if (key < year)
            {
                if (!full_history.empty())
                {
                    if (full_history[full_history.size() - 1] != value)
                        full_history.push_back(value);
                }
                else
                {
                    full_history.push_back(value);
                }
            }
            else
                break;
        }

        if (!full_history.empty())
        {
            string current_name = GetHistory(year, names);

            if (full_history[full_history.size() - 1] == current_name)
            {
                full_history.erase(full_history.begin() + (full_history.size() - 1));
            }
            reverse(full_history.begin(), full_history.end());
        }

        string result = "";
        for (const auto& item : full_history)
        {
            if (!result.empty())
            {
                result = result + ", " + item;
            }
            else
            {
                result += item;
            }
        }

        if (!result.empty())
            return " (" + result + ") ";
        return result ;
    }
};
