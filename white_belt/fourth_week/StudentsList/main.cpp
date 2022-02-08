#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string first_name = "";
    string last_name = "";
    int day = 0;
    int month = 0;
    int year = 0;
};

Student ReadStudent() {
    Student student;
    cin >> student.first_name >> student.last_name >> student.day >> student.month >> student.year;
    return student;
}

void PrintStudentName(const Student& student) {
    cout << student.first_name << " " << student.last_name << endl;
}

void PrintStudentDate(const Student& student) {
    cout << student.day << "." << student.month << "." << student.year << endl;
}

int main() {
    int count = 0;
    cin >> count;

    vector <Student> students;

    for (int i = 0; i < count; ++i) {
        students.push_back(ReadStudent());
    }

    count = 0;
    cin >> count;

    for (int i = 0; i < count; ++i) {
        string current_command;
        int student_number;

        cin >> current_command >> student_number;

        if (current_command == "name") {
            if (student_number <= students.size() && student_number != 0) {
                PrintStudentName(students[student_number - 1]);
            } else {
                cout << "bad request" << endl;
            }
        } else if (current_command == "date") {
            if (student_number <= students.size() && student_number != 0) {
                PrintStudentDate(students[student_number - 1]);
            } else {
                cout << "bad request" <<  endl;
            }
        } else {
            cout << "bad request" <<  endl;
        }
    }

    return 0;
}
