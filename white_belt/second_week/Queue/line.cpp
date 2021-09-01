/*
Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда.
Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.

Будем считать, что люди в очереди нумеруются целыми числами, начиная с 0.

Реализуйте обработку следующих операций над очередью:

WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
QUIET i: пометить i-го человека как успокоившегося;
COME k: добавить k спокойных человек в конец очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.

Формат ввода
Количество операций Q, затем описания операций.

Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.

Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

Формат вывода
Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void    PrintVector(const vector<T>& vtr) {
    for (auto v : vtr) {
        cout << v << " ";  
    }
}

void    PrintWorryCount(const vector <bool>& people) {
    int counter = 0;
    
    for (auto p : people) {
        if (p == true) {
            counter++;
        }
    }
    cout << counter << endl;
}

int     main() {
    int             count_of_operation;
    vector <bool>   persons;

    cin >> count_of_operation;
    vector <string> operations(count_of_operation);
    vector <int>    index(count_of_operation);
    
    for (int i = 0; i < count_of_operation; ++i) {
        cin >> operations[i];
        if (operations[i] == "WORRY_COUNT") {
            index[i] = 0;
        }
        else {
            cin >> index[i];
        }
    }

    cout << endl << endl;
    for (int j = 0; j < count_of_operation; ++j) {
        if (operations[j] == "WORRY") {
            persons[index[j]] = true;
        }
        else if (operations[j] == "QUIET") {
            persons[index[j]] = false;
        }
        else if (operations[j] == "COME") {
            if (index[j] > 0) {
                for (int c = 0; c < index[j]; c++) {
                    persons.push_back(false);
                }
            }
            else {
                index[j] *= -1;
                persons.resize(persons.size() - index[j]);
            }
        }
        else if (operations[j] == "WORRY_COUNT") {
            PrintWorryCount(persons);
        }
    }
    return 0;
}
