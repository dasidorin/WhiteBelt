#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");

    int lines = 0;
    int columns = 0;
    if (input) {
        input >> lines;
        input.ignore(1) >> columns;
    }

    int i = 0;
    while (i < lines) {

        int j = 0;
        while (j < columns) {

            if (input) {

                if (j != 0 && j != columns)
                {
                    input.ignore(1);
                }

                int current_number = 0;
                input >> current_number;
                cout << setw(10) << current_number;
            }

            j++;
            if (j != columns) {
                cout << ' ';
            }
        }

        i++;
        if (i != lines) {
            cout << endl;
        }
    }

    return 0;
}
