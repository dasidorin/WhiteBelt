#include <iostream>
#include <string>

using namespace std;

int main()
{
	string	a;
	int		res;

	cin >> a;
	res = -2;

	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == 'f' && res == -2)
			res = -1;
		else if (a[i] == 'f' && res == -1)
		{
			res = i;
			break;
		}
	}
	cout << res << endl;
	return (0);
}
