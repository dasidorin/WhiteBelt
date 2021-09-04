#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename T1>
void PrintVector(const vector <T1>& vtr)
{
	for (const auto& v : vtr)
	{
		cout << v << " ";
	}
}

bool CompareByModule(const int& a, const int& b)
{
	return abs(a) < abs(b);
}

int main()
{
	int n = 0;
	cin >> n;

	vector <int> nums(n);
	for (auto& i : nums)
	{
		cin >> i;
	}
	sort(begin(nums), end(nums), CompareByModule);
	PrintVector(nums);
	return 0;
}
