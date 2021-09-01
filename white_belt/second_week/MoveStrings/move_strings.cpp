#include <iostream>
#include <vector>
#include <string>

/*
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination,
и дописывает все строки из первого вектора в конец второго.
После выполнения функции вектор source должен оказаться пустым.
*/

using namespace std;

void    MoveStrings(vector <string>& source, vector <string>& destination) {
    for (auto s : source) {
        destination.push_back(s);
    }
    source.clear();
}
