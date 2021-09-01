#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
	int q;
	cin >> q;

	map <set <string>, int> buses;
	int current_route = 1;
	for (int i = 0; i < q; ++i)
	{
		int stops_count;
		cin >> stops_count;
		set <string> current_stops;
		for (int j = 0; j < stops_count; ++j)
		{
			string stop;
			cin >> stop;
			current_stops.insert(stop);
		}

		if (buses.count(current_stops) == 0)
		{
			buses[current_stops] = current_route;
			cout << "New bus " << current_route << endl;
			current_route += 1;
		}
		else
		{
			cout << "Already exists for " << buses[current_stops] << endl;
		}
	}
	return 0;
}
