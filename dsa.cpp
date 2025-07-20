#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    int roll;
    float marks;

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Name: " << name << ", Roll No: " << roll << ", Marks: " << marks << endl;
    }
};

class StudentSystem {
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        s.input();
        students.push_back(s);
        cout << " Student added successfully!\n";
    }

    void viewAll() {
        if (students.empty()) {
            cout << "No records found.\n";
            return;
        }
        cout << " All Students:\n";
        for (const auto &s : students)
            s.display();
    }

    void searchByRoll() {
        int roll;
        cout << "Enter roll number to search: ";
        cin >> roll;
        bool found = false;
        for (const auto &s : students) {
            if (s.roll == roll) {
                cout << " Student Found:\n";
                s.display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << " No student found with roll number " << roll << ".\n";
    }

    void sortByMarks() {
        sort(students.begin(), students.end(), [](Student a, Student b) {
            return a.marks > b.marks;
        });
        cout << "Students sorted by marks (High to Low):\n";
        viewAll();
    }

    void showTopper() {
        if (students.empty()) {
            cout << "No records found.\n";
            return;
        }
        float topMarks = students[0].marks;
        for (const auto &s : students)
            topMarks = max(topMarks, s.marks);

        cout << " Topper(s):\n";
        for (const auto &s : students) {
            if (s.marks == topMarks)
                s.display();
        }
    }
};

int main() {
    StudentSystem system;
    int choice;

    do {
        cout << "\n=====  STUDENT REPORT CARD SYSTEM =====\n";
        cout << "1. Add Student\n2. View All Students\n3. Search Student by Roll No\n4. Sort by Marks\n5. Show Topper\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.addStudent(); break;
            case 2: system.viewAll(); break;
            case 3: system.searchByRoll(); break;
            case 4: system.sortByMarks(); break;
            case 5: system.showTopper(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << " Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
