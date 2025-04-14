#include <iostream>
using namespace std;

class InvalidHour {
public:
    string error(){
        return "Hour must be between 0 and 24.";
    }
};

class InvalidMinute {
public:
    string error(){
        return "Minute must be between 0 and 59.";
    }
};

class Time {
    int hr, min;
public:
    Time() {
        hr = min = 0;
    }

    void getData() {
        cout << "Enter the hour: ";
        cin >> hr;
        if (hr < 0 || hr > 24) {
            throw InvalidHour();
        }

        cout << "Enter the minute: ";
        cin >> min;
        if (min < 0 || min >= 60) {
            throw InvalidMinute();
        }
    }

    Time operator +(Time T) {
        Time temp;
        temp.min = min + T.min;
        int m = temp.min / 60;
        temp.min = temp.min % 60;
        temp.hr =  m + hr + T.hr;
        return temp;
    }

    bool operator>(Time T) {
        if (hr > T.hr){
             return true;
        }
        else if (hr == T.hr && min > T.min){
             return true;
        }
        else {
        return false;
        }
    }

    void display() {
        cout << hr << " hr " << min << " min" << endl;
    }
};

int main() {
    Time T1, T2, T3;
    
    try {
        cout << "Enter first time:" <<endl;
        T1.getData();
        
        cout << "Enter second time:" <<endl;
        T2.getData();

        T3 = T1 + T2;
        cout << "Sum of the times: ";
        T3.display();

        cout<<"Comparision between the given times: "<<endl;
        if (T1 > T2) {
            cout << "First time is greater." <<endl;
        }
        else if (T2 > T1) {
            cout << "Second time is greater." <<endl;
        }
        else {
            cout << "Both times are equal." <<endl;
        }
    }
    catch (InvalidHour& invalid) {
        cout << "Exception caught: " << invalid.error() <<endl;
    }
    catch (InvalidMinute& invalid) {
        cout << "Exception caught: " << invalid.error() <<endl;
    }

    return 0;
}
