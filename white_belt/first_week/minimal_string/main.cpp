/*
В стандартном потоке даны три строки, разделённые пробелом.
Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов.
Выведите в стандартный вывод лексикографически минимальную из них.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2, str3;

    cin >> str1 >> str2 >> str3;
    if (str1 <= str2 && str1 <= str3) {
        cout << str1;
    }
    else if (str2 <= str1 && str2 <= str3) {
        cout << str2;
    }
    else {
        cout << str3;
    }
    return 0;
}
