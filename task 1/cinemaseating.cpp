#include <iostream>
using namespace std;

int main() {
    char seats[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            seats[i][j] = 'O';
        }
    }

    int rows, cols, choice;
    do{
        cout<<"\tCinema Ticket Booking System"<<endl;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cout<<seats[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"Enter the row of the seat (1-5): ";
        cin>>rows;

        cout<<"Enter the column of the seat (1-5): ";
        cin>>cols;

        if(rows < 1 || rows > 5 && cols < 1 || cols > 5){
            cout<<"Invalid input! Please choose between the numbers 1-5."<<endl;
        }

        else if(seats[rows - 1][cols - 1]== 'X'){
            cout<<"Seat already booked. Please choose other available seats."<<endl;
        }

        else{
            seats[rows - 1][cols -1] = 'X';
            cout<<"Seat booked successfully! Thank you."<<endl;
        }
        cout << "Do you want to make another booking? (0/1): ";
        cin >> choice;
    }while(choice == 0);
    
    return 0;
}