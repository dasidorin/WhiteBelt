#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
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
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
