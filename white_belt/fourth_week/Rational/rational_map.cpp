#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int GetGcd(int a, int b) {
    while ( a != b) {
        if ( a < b) {
            b = b - a;
        } else {
            a = a - b;
        }
    }
    return a;
}

int GetLcm(int a, int b) {
    int res = 0;

    if ((a * b) % GetGcd(a, b) == 0) {
        res = (a * b) / GetGcd(a, b);
    } else {
        res = a * b;
    }
    return res;
}

class Rational {
public:
    Rational() {
        SetDefault();
    }

    Rational(int numerator, int denominator) {
        if (numerator == 0) {
            SetDefault();
        } else {
            GetReduction(numerator, denominator);
        }
    }

    int Numerator() const {
        return current_numerator;
    }

    int Denominator() const {
        return current_denominator;
    }

    Rational Reverse()  {
        if (current_numerator) {
            return Rational(current_denominator, current_numerator);
        } else {
            return Rational(0, 1);
        }
    }
private:
    int current_numerator;
    int current_denominator;

    void SetDefault() {
        current_numerator = 0;
        current_denominator = 1;
    }

    void GetReduction(int numerator, int denominator) {

        bool flag = false;

        if (numerator < 0 && denominator > 0) {
            flag = true;
            numerator *= -1;
        } else if (numerator > 0 && denominator < 0) {
            flag = true;
            denominator *= -1;
        } else if (numerator < 0 && denominator < 0) {;
            numerator *= -1;
            denominator *= -1;
        }

        int delimiter = GetGcd(numerator, denominator);

        current_numerator = numerator / delimiter;
        current_denominator = denominator / delimiter;

        if (flag) {
            current_numerator *= -1;
        }
    }
};

bool operator == (const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    }
    return false;
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    int mn1 = GetLcm(lhs.Denominator(), rhs.Denominator()) / lhs.Denominator();
    int mn2 = GetLcm(lhs.Denominator(), rhs.Denominator()) / rhs.Denominator();

    if (lhs.Numerator() * mn1 < rhs.Numerator() * mn2) {
        return true;
    }

    return false;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
