#include <iostream>
using namespace std;

class Stack {
    int arr[10];
    int top;
public:
    Stack(){
        top = -1;
    }

    void push(int value){
        if(top < 9){
            top++;
            arr[top] = value;
            cout<<value<<" pushed into stack."<<endl;
        } else {
            cout << "Stack is full."<<endl;
        }
    }

    void pop(){
        if (top >= 0) {
            cout << arr[top]<<" popped from stack."<<endl;
            top--;
        } else {
            cout << "Stack is empty."<<endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        } else{
            cout << "Stack is empty.\n";
            return 1;
        }
    }

    void findMiddle(){
        if(top == -1){
            cout << "Stack is empty.\n";
            return;
        }
        int middleIndex = top / 2;
        cout<<"Middle element is: "<<arr[middleIndex]<<endl;
    }

    void reverseBottomHalf() {
        if(top == -1){
            cout<<"Stack is empty.\n";
            return;
        }
        int half = (top + 1) / 2; 
        for(int i = 0; i<half / 2; i++){
            int temp = arr[i];
            arr[i] = arr[half-1-i];
            arr[half-1-i] = temp;
        }
        cout << "Bottom half reversed.\n";
    }

    void display() {
        if(top == -1){
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for(int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    s.display();  
    s.findMiddle();  
    s.reverseBottomHalf();  
    s.display(); 
    s.pop();
    s.display();
    cout<<"Top element is: " <<s.peek()<<endl;

    return 0;
}
