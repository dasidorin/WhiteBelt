#include <iostream>
#include <exception>
#include <stdexcept>

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

    Rational Reverse() const {
        if (current_numerator != 0) {
            return Rational(current_denominator, current_numerator);
        } else {
            throw domain_error("");
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

        if (denominator == 0) {
            throw invalid_argument("");
        }

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

Rational operator * (Rational lhs, Rational rhs) {
    return  Rational({lhs.Numerator() * rhs.Numerator()}, {lhs.Denominator() * rhs.Denominator()});
}

Rational operator / (Rational lhs, Rational rhs) {
    return (lhs * rhs.Reverse());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
