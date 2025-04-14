#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void inputBooks(char books[10][150]) {
    cout << "Enter 10 book titles (max 150 characters each):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Title " << (i + 1) << ": ";
        cin.getline(books[i], 150);
    }
}

void writeToFile(char fileName[], char books[10][150]) {
    ofstream write(fileName, ios::binary);
    if (write) {
        for (int i = 0; i < 10; i++) {
            write.write(books[i], 150);
        }
        write.close();
    } else {
        cout << "Error opening file for writing." << endl;
    }
}

void readFromFile(char fileName[], char books[10][150]) {
    ifstream inFile(fileName, ios::binary);
    if (inFile) {
        for (int i = 0; i < 10; i++) {
            inFile.read(books[i], 150);
        }
        inFile.close();
    } else {
        cout << "Error opening file for reading." << endl;
    }
}

bool findBooks(char books[10][150], char searchTitle[]) {
    for (int i = 0; i < 10; i++) {
        if (strncmp(books[i], searchTitle, 150) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char books[10][150];
    char fileName[100];
    char searchTitle[150];

    cout << "Enter filename to save the book titles: ";
    cin.getline(fileName, 100);

    inputBooks(books);

    writeToFile(fileName, books);

    cout << "\nEnter a title to search for: ";
    cin.getline(searchTitle, 150);

    readFromFile(fileName, books);

    if (findBooks(books, searchTitle)) {
        cout << "The title is saved in the file!" <<endl;
    } 
    else {
        cout << "The title is not saved in the file!" <<endl;
    }

    return 0;
}
