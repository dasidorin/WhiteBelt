#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }

    void ApplyPart(double& some_value) const {
        switch (operation) {
            case '+' :
                some_value += value;
                break;
            case '-' :
                some_value -= value;
                break;
            case '/' :
                some_value /= value;
                break;
            case '*' :
                some_value *= value;
                break;
        }
    }

    void InvertPart() {
        if ( operation == '+' ) {
            operation = '-';
        } else if ( operation == '-' ) {
            operation = '+';
        } else if (operation == '*') {
            operation = '/';
        } else {
            operation = '*';
        }
    }
private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char new_operation, double new_value) {
        parts.push_back({new_operation, new_value});
    }

   double Apply(double some_value) const {
        for (const auto& part : parts) {
            part.ApplyPart(some_value);
        }
       return some_value;
    }

    void Invert() {
        for (auto& part : parts) {
            part.InvertPart();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector <FunctionPart> parts;
};
