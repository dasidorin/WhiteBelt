/*
Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v,
в которой числа переставлены в обратном порядке.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int>     Reversed(const vector<int>& v) {
    vector <int>    revers;
    int             i;

    i = v.size() - 1;
    while (i >= 0) {
        revers.push_back(v[i]);
        i--;
    }
    return revers;
}
