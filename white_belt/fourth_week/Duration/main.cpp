#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;

    Duration (int h = 0, int m = 0) {
        int total = 60 * h + m;
        hour = total / 60;
        min = total % 60;
    };
};

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0') << setw(2) << duration.hour << ":"
            << setfill('0') << setw(2) << duration.min;
    return stream;
}

int main() {
    Duration dur1 {1, 5};
    cout << dur1 << endl;
    return 0;
}
