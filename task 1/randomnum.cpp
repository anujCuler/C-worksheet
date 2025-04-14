#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 

    int choice, guess, number, to;
    int from = 1;
    cout << "Enter your choice ('1' for EASY, '2' for MEDIUM, '3' for HARD): ";
    cin >> choice;

  
    switch(choice){
        case 1:
        to = 8;
        break;
    
        case 2:
        to = 30;
        break;
    
        case 3:
        to = 50;
        break;
        
        default:
        cout << "Invalid input! Exiting game.\n";
    }
        
    number = rand() % to + 1; 
    


    while (choice == 1 || choice == 2 || choice == 3) {
        cout << "Guess the number between 1 and " << to << ": ";
        cin >> guess;
    
        if (guess < number){
            cout << "Too low! Try again: ";
        }
        else if (guess > number){
            cout << "Too high! Try again: ";
        }
        else  {
            cout << "Congratulations! You guessed the correct number!\n";
            break;
        }
        
       
    }

    return 0;
}
