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

// Load students from file
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


// Save students to file
void saveStudents(string filename, Student students[], int count) {
    // Directly use std::string with ofstream constructor
    ofstream file(filename);

    // Loop through and write student data to file
    for (int i = 0; i < count; i++) {
        file << students[i].roll << " " << students[i].name << " " << students[i].marks <<endl;
    }
}


// Add a student
int addStudent(Student students[], int count) {
    if (count < 100) {
        students[count].read();  // Directly call read on the current student
        cout << "Student added.\n";
        return count + 1;
    }
    cout << "Cannot add more students. Limit reached.\n";
    return count;
}

int main() {
    Student students[100];
    int total = loadStudents("students.txt", students);  // Load students from file

    char choice;  // Initialize choice to something other than '2' to enter the loop
    while (choice != '2') {
        // Display the menu directly inside the loop
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Save & Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == '1') {
            total = addStudent(students, total);  // Add a student
        } 
        else if (choice == '2') {
            saveStudents("students.txt", students, total);  // Save and exit
            cout << "Saved and exiting.\n";
        } 
        else {
            cout << "Invalid option.\n";  // Handle invalid input
        }
    }

    return 0;
}
