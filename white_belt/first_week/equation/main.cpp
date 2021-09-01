#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double a, b, c;

    cin >> a >> b >> c;
    double D, x;
    
    if (a == 0 && b != 0)
    {
        x = -c / b;
        cout << x << endl;
        return 0;
    }
    else if (b == 0 && a == 0)
    {
        cout << endl;
        return 0;
    }
    else if (c == 0 && a == 0)
    {
        x = 0;
        cout << x << endl;
        return 0;
    }

    D = b * b - 4 * a * c;
    if (D > 0)
    {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << x1 << " " << x2 << endl;
    }
    else if (D == 0)
    {
        x = -b / (2 * a);
        cout << x << endl;
    }
    else
    {
        cout << endl;
    }
    return 0;
}