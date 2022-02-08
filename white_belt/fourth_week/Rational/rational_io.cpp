#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

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
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct) {
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 7;
        }
    }

    cout << "OK" << endl;
    return 0;
}
