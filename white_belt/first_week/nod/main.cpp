#include <iostream>

using namespace std;
/*
В stdin даны два натуральных числа. Выведите в stdout их наибольший общий делитель.
*/


int     main()
{
    int a, b;

    cin >> a >> b;

    while (a != b)
    {
        if (a < b)
            b = b - a;
        else
            a = a - b;
    }
    cout << a << endl;
    return 0;
}
