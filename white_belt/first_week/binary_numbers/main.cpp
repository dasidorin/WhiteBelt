#include <iostream>
#include <vector>

/*
На вход дано целое положительное число N.
Выведите его в двоичной системе счисления без ведущих нулей
*/

using namespace std;


static void convert_to_binary(int a, vector <int> *binary)
{
    if (a <= 1)
        binary->push_back(a);
    else {
        convert_to_binary(a / 2, binary);
        binary->push_back(a % 2);
    }
}

int         main()
{
    int             a;
    vector <int>    binary;
    int             i;

    cin >> a;
    convert_to_binary(a, &binary);

    i = 0;
    while (binary[i] == 0)
        i++;
    for (i; i < binary.size(); i++)
        cout << binary[i];
    cout << endl;
    return 0;
}
