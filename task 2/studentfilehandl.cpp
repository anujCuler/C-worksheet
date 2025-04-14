#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;

    Student() {
        roll = 0;
        name = "";
        marks = 0;
    }

    void read() {
        cout << "Enter roll number: ";
        cin >> roll;

        cout << "Enter name: ";
        cin >> name;

        while (true) {
            cout << "Enter marks (0 to 100): ";
            cin >> marks;

            if (marks >= 0 && marks <= 100) {
                break;
            } else {
                cout << "Invalid marks. Try again.\n";
            }
        }
    }
};

int loadStudents(string filename, Student students[]) {
    ifstream file(filename);
    int count = 0;

    if (!file) {
        cout << "File not found. Starting with empty list.\n";
        return 0;
    }

    while (file >> students[count].roll >> students[count].name >> students[count].marks) {
        if (students[count].marks >= 0 && students[count].marks <= 100) {
            count++;
        } else {
            cout << "Invalid marks for roll " << students[count].roll<<endl;
        }

        if (count == 100) {
            cout << "Maximum limit of 100 students reached.\n";
            return count;
        }
    }

    return count;
}

void saveStudents(string filename, Student students[], int count) {
    ofstream file(filename, ios::app);
    for (int i = 0; i < count; i++) {
        file << students[i].roll << " " << students[i].name << " " << students[i].marks <<endl;
    }
}

int addStudent(Student students[], int count) {
    if (count < 100) {
        students[count].read(); 
        cout << "Student added.\n";
        return count + 1;
    }
    cout << "Cannot add more students. Limit reached.\n";
    return count;
}

int main() {
    Student students[100];
    int total = loadStudents("studentrecord.txt", students); 

    char choice;
    while (choice != '2') {
      
        cout << "\nMenu:"<<endl;
        cout << "1. Add Student"<<endl;
        cout << "2. Save & Exit"<<endl;
        cout << "Choose: ";
        cin >> choice;

        if (choice == '1') {
            total = addStudent(students, total);
        } 
        else if (choice == '2') {
            saveStudents("studentrecord.txt", students, total);
            cout << "Saved and exiting.\n";
        } 
        else {
            cout << "Invalid option."<<endl;
        }
    }

    return 0;
}
