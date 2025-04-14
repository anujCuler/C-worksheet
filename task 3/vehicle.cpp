#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
protected:
    string regNo;
    string color;
public:
    Vehicle(string reg, string col) {
        regNo = reg;
        color = col;
    }
     void saveToFile() {
        ofstream file("vehicle.txt", ios::app);
        if (file) {
            file << "RegNo: " << regNo << ", Color: " << color << endl;
        } else {
            cout << "Couldn't open file!" << endl;
        }
    }
   
    
};

class Car : public Vehicle {
    int seats;
public:
    Car(string reg, string col, int s) : Vehicle(reg, col) {
        seats = s;
    }
    void saveToFile() {
        ofstream file("car.txt", ios::app);
        if (file) {
            file << "RegNo: " << regNo << ", Color: " << color << ", Seats: " << seats <<endl;
        } 
        else {
            cout << "Couldn't open the car file!" << endl;
        }
    }
};

class Bike : public Vehicle {
    int engineCC;
public:
    Bike(string reg, string col, int cc) : Vehicle(reg, col) {
        engineCC = cc;
    }
    void saveToFile() {
        ofstream file("bike.txt", ios::app);
        if (file) {
            file << "RegNo: " << regNo << ", Color: " << color << ", Engine: " << engineCC << "cc" <<endl;
        } 
        else {
            cout << "Couldn't open the bike file!" << endl;
        }
    }
};

int main() {
    Car myCar("BaP1122", "Blue", 5);
    Bike myBike("GaP1414", "Green", 200);

    myCar.saveToFile();
    myBike.saveToFile();

    cout << "The data has been saved successfully." << endl;
    return 0;
}
