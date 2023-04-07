#include<iostream>

using namespace std;

class Student {
    char Name;
    char Id;

};

int main() {
    int choice;
    cout << "Student management system using C++" << endl;
    cout << "===================================" << endl;
    cout << "[1]. Add a new student" << endl;
    cout << "[2]. Show all students" << endl;
    cout << "[3]. Add a new course" << endl;
    cout << "[4]. Show all courses" << endl;
    cout << "[5]. Edit a student" << endl;
    cout << "[6]. Delete a student" << endl;
    cout << "[7]. Delete a course" << endl;
    cout << "[8]. Exit" << endl;
    cin >> choice;
    
    return 0;
}