#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T1>
void	PrintVector(const vector <T1>& v) {
	for (auto c : v) {
		cout << c << " ";
	}
}

template <typename T2>
void	PrintVectorEndl(const vector <T2>& v) {
	PrintVector(v);
	cout << endl;
}

void 	AddAffairsToDay(vector <vector<string>>& affairs, int day_number, string affair) {
		affairs[day_number - 1].push_back(affair);
}

void	DumpAffairsAsignedToDay(const vector<vector<string>>& affairs, int day_number) {
	cout << affairs[day_number - 1].size();
	if (affairs[day_number - 1].size() > 0) {
		cout << " ";
		PrintVectorEndl(affairs[day_number - 1]);
	}
	else
		cout << endl;
}

vector <vector <string>>	NextMounth(int mounth_index, const vector <int>& days_in__mounth, vector <vector <string>>& affairs)
{
	vector <vector <string>> new_affairs;
	
	if (days_in__mounth[mounth_index] < affairs.size()) {
		int i = days_in__mounth[mounth_index] - 1;
		for (int j = i; j < affairs.size(); ++j) {
			if (j != i) {
				for (auto c : affairs[j]) {
					affairs[i].push_back(c);
				}
			}
		}
	}
	affairs.resize(days_in__mounth[mounth_index]);
	new_affairs.insert(end(new_affairs), begin(affairs), end(affairs));
	return (new_affairs);
}

int		main() {
	vector <int> days_in_mounth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int		count_of_operation;
	int		day_number;
	int		mounth_index = 0;
	vector <vector <string>> affairs (days_in_mounth[mounth_index]);
	string	task;
	
	cin >> count_of_operation;
	
	vector <string> operations (count_of_operation);
	vector <int>	indexes (count_of_operation);
	vector <string> tasks (count_of_operation);

	for (int i = 0; i < count_of_operation; ++i) {
		cin >> operations[i];
		if (operations[i] == "ADD") {
			cin >> indexes[i];
			cin >> tasks[i];
			AddAffairsToDay(affairs, indexes[i], tasks[i]);
		}
		else if (operations[i] == "DUMP") {
			cin >> indexes[i];
			tasks[i] == "";
		}
		else if (operations[i] == "NEXT") {
			mounth_index++;
			if (mounth_index > 11)
				mounth_index = 0;
			affairs = NextMounth(mounth_index, days_in_mounth, affairs);
			tasks[i] = "";
			indexes[i] = 0;
		}
	}

	for (int t = 0; t < count_of_operation; ++t) {
		if (operations[t] == "DUMP") {
			DumpAffairsAsignedToDay(affairs, indexes[t]);
		}
	}

	cout << "mounth index = " << mounth_index << endl;
	for (int aa = 0; aa < affairs.size(); ++aa) {
		cout << aa + 1 << '\t';
		PrintVectorEndl(affairs[aa]);
	}
	return 0;
}