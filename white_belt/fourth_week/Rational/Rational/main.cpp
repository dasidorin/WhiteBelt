#include <iostream>
using namespace std;

class Rational {
public:
	Rational() {
		current_numerator = 0;
		current_denominator = 1;
	}

	Rational(int numerator, int denominator) {
		if (numerator == 0) {
			current_numerator = 0;
			current_denominator = 1;
		} else {
			bool flag = false;
			if (numerator < 0) {
				flag = true;
				numerator *= -1;
			}

			if (denominator < 0) {
				flag = true;
				denominator *= -1;
			}

			int delimiter = GetGcd(numerator, denominator);

			if (delimiter) {
				current_numerator = numerator / delimiter;
				current_denominator = denominator / delimiter;
			} else {
				current_numerator = numerator;
				current_denominator = denominator;
			}

			if (flag) {
				current_numerator *= -1;
			}
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
};

int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}
