#include <iostream>
#include <vector>

using namespace std;


/*
Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.
*/


void    Reverse(vector <int>& v) {
    vector <int>    swp;
    int             i;

    i = v.size() - 1;
    while (i >= 0)  {
        swp.push_back(v[i]);
        i--;
    }
    i = 0;
    for (auto s : swp) {
        v[i] = swp[i];
        i++;
    }
}

