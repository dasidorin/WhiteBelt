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
            throw domain_error("Division by zero");
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
            throw invalid_argument("Invalid argument");
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

Rational operator * (Rational lhs, Rational rhs) {
    return  Rational({lhs.Numerator() * rhs.Numerator()}, {lhs.Denominator() * rhs.Denominator()});
}

Rational operator / (Rational lhs, Rational rhs) {
    return (lhs * rhs.Reverse());
}

ostream& operator << (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& rational) {
    int numerator = 0;
    int denominator = 0;

    if (!(stream >> numerator)) {
        return stream;
    }

    char delimiter;

    if (!(stream >> delimiter) || delimiter != '/') {
        return stream;
    }

    if (!(stream >> denominator)) {
        return stream;
    }

    rational = Rational(numerator, denominator);
    return stream;
}

int main() {

    Rational lhs, rhs;
    char operation;

    try {
        cin >> lhs >> operation >> rhs;
    } catch (exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    try
    {
        switch (operation) {
        case '+':
            cout << lhs + rhs;
            break;
        case '-':
            cout << lhs - rhs;
            break;
        case '*':
            cout << lhs * rhs;
            break;
        case '/':
            cout << lhs / rhs;
            break;
        }
    } catch (exception& e) {
        cout << e.what() << endl;
        return 2;
    }
    return 0;
}
