/*
Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.

Гарантируется, что среднее арифметическое значений температуры является целым числом.

Формат ввода
Вводится число N, затем N неотрицательных целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.

Формат вывода
Первое число K — количество дней, значение температуры в которых выше среднего арифметического. Затем K целых чисел — номера этих дней.

*/

#include <iostream>
#include <vector>

using namespace std;

void    PrintVector(const vector<int>& vtr) {
    for (auto v : vtr) {
        cout << v << " ";
    }
}

int main() {
    int n;

    cin >> n;

    vector <int> temperature(n);
    for (auto& t : temperature) {
        cin >> t;
    }
    int  summ = 0;
    for (auto c : temperature) {
        summ += c;
    }
    int count = 0;
    vector <int> index;
    for (int j = 0; j < n; ++j) {
        if (temperature[j] > summ / n) {
            count++;
            index.push_back(j);
        }
    }
    cout << count << endl;
    PrintVector(index);
    return 0;
}
