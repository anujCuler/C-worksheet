#include <iostream>
using namespace std;
int main(){
    int choice;
    cout<<"Please chooose from 1-6 for the day you want to be displayed!"<<endl;
    cout<<"Enter 1 for Sunday\n"<< "Enter 2 for Monday\n"<<"Enter 3 for Tuesday\n"<<"Enter 4 for Wednesday\n"<<"Enter 5 for Thursday\n"<<
    "Enter 6 for Friday\n"<<"Enter 7 for Saturday\n"<<"Please enter your choice : "; 
    cin>>choice;
    switch (choice){
        case 1:
        cout<<"It is Sunday."<<endl;
        break;

        case 2:
        cout<<"It is Monday."<<endl;
        break;

        case 3:
        cout<<"It is Tuesday."<<endl;
        break;

        case 4:
        cout<<"It is Wednesday."<<endl;
        break;

        case 5:
        cout<<"It is Thursday."<<endl;
        break;

        case 6:
        cout<<"It is Friday."<<endl;
        break;

        case 7:
        cout<<"It is Saturday."<<endl;
        break;

        default:
        cout<<"Invalid input!";
    }
    return 0;
}