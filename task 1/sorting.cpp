#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array you want to create and sort: "<<endl;
    cin>>n;

    int array[n];
    cout<<"enter the integers for the array: "<<endl;
    for(int i=0;i<n;i++){
        
        cin>>array[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(array[j]<array[i]){
                int third;
                third = array[j];
                array[j] = array [i];
                array[i] = third;
            }
        }
    }
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}