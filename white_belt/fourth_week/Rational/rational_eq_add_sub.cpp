#include <iostream>
#include <numeric>

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

// Реализуйте для класса Rational операторы ==, + и -

bool operator == (const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    }
    return false;
}

Rational operator + (Rational lhs, Rational rhs) {
    int mn1 = GetLcm(lhs.Denominator(), rhs.Denominator()) / lhs.Denominator();
    int mn2 = GetLcm(lhs.Denominator(), rhs.Denominator()) / rhs.Denominator();

    return Rational({lhs.Numerator() * mn1 + rhs.Numerator() * mn2}, {lhs.Denominator() * mn1});
}

Rational operator - (Rational lhs, Rational rhs) {
    int mn1 = GetLcm(lhs.Denominator(), rhs.Denominator()) / lhs.Denominator();
    int mn2 = GetLcm(lhs.Denominator(), rhs.Denominator()) / rhs.Denominator();

    return Rational({lhs.Numerator() * mn1 - rhs.Numerator() * mn2}, {lhs.Denominator() * mn1});
}


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
