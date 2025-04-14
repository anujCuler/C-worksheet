#include <iostream>
using namespace std;
int main(){
    int choice;
    float C, F;
    retry:
    cout<<"Enter '1' for conversion from celsius to fahrenheit or '2' for fahrenheit to celsius:  ";
    cin>>choice;
   if(choice==1){
    cout<<"Enter the degree celcius: ";
    cin>>C;
    F = (C * 9/5) + 32;
    cout<<"The given degree celsius in fahrenheit is:"<<" "<<F<<endl;
   }
    else if (choice==2){
        cout<<"Enter the degree fahrenheit: ";
        cin>>F;
        C = (F - 32) * 5/9;
        cout<<"The given degree fahrenheit in celsius is:"<<" "<<C<<endl;
    }
    else {
        cout<<"Invalid choice/input!"<<endl;
        goto retry;
    }

   
    return 0;
}