#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    static int a;

    a++;
    if (a % 2 == 0) {
        throw system_error(error_code());
    } else
        return "01:02:03";
}

class TimeServer {
public:
    string GetCurrentTime() {
        string result = last_fetched_time;
        try {
            result = AskTimeServer();
        } catch (system_error& er) {
            return result;
        }
        last_fetched_time = result;
        return result;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
