#include <iostream>
using namespace std;
int main(){
    int num , bounce , bounce1;
    bool increasing = false;
    bool decreasing = false;
    cout<<"enter some numbers: ";
    cin>>num;
    if(num<100){
        cout<<"The number is not bouncy!"<<endl;
    }
     bounce = num % 10;
     num /= 10;

     while(num>0){
        bounce1 = num % 10;
        if(bounce > bounce1){
            increasing = true;
        }
        if(bounce < bounce1){
            decreasing = true;
        }
        bounce = bounce1;
        num /= 10;
     }

     if(increasing && decreasing){
        cout<<"The number is BOUNCY!!"<<endl;
     }
     else{
        cout<<"The number is not BOUNCY!"<<endl;
     }
    return 0;
}