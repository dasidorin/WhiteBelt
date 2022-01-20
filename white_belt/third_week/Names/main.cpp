#include <iostream>
#include <string>
#include <vector>
#include <map>

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

private:
    map <int, string> first_names;
    map <int, string> last_names;

    string GetHistory(int year, const map<int, string>& names)
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
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}
