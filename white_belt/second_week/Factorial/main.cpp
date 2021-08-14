#include <iostream>

/*
Напишите функцию, которая

называется Factorial
возвращает int
принимает int и возвращает факториал своего аргумента.
Гарантируется, что аргумент функции по модулю не превышает 10.
Для отрицательных аргументов функция должна возвращать 1.
*/

using namespace std;

int     Factorial(int x) {
    int res;

    if (x <= 0)
        return 1;
    res = 1;
    for (int i = 1; i <= x; ++i) {
        res *= i;
    }
    return res;
}
