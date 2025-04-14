#include <iostream>
using namespace std;

class Queue {
private:
    int arr[10];
    int front, rear, size;

public:
    Queue(){
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int value){
        if (size == 10) {
            cout << "Queue is full!"<<endl;
            return;
        }
        rear++;
        arr[rear] = value;
        size++;
    }

    int dequeue(){
        if(size == 0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        int val = arr[front];
        front++;
        size--;
        return val;
    }

    void display() {
        if (size == 0) {
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<<"Queue: ";
        for(int i = front; i <= rear; i++){
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }

    void reverseFirstK(int k) {
        if(k > size || k <= 0){
            cout<<"Invalid value of K."<<endl;
            return;
        }

        int start = front;
        int end = front + k - 1;

        while(start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void interleaveQueue(){
        if(size % 2 != 0){
            cout<<"Queue size must be even to interleave."<<endl;
            return;
        }
        int half = size / 2;
        int temp[10];

        for (int i = 0; i < half; i++){
            temp[i] = arr[front + i];
        }
        int index = front;
        for (int i = 0; i < half; i++) {
            arr[index++] = temp[i];                
            arr[index++] = arr[front + half + i];  
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    cout<<"After reversing first 3 elements:"<<endl;
    q.reverseFirstK(3);
    q.display();
    cout<<"After interleaving first and second half:"<<endl;
    q.interleaveQueue();
    q.display();

    return 0;
}
