#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = 0;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = 0;
    }

    void addStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addEnd(int value) {
        Node* newNode = new Node(value);
        if (head == 0) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addPosition(int value, int position) {
        if (position == 1) {
            addStart(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == 0) {
                cout << "Position out of range.\n";
                return;
            }
            temp = temp->next;
        }
        if (temp == 0) {
            cout << "Position out of range.\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != 0) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void printNthfromEnd(int n){
        int count = 0;
        Node* temp = head;
        while(temp != 0) {
            count++;
            temp = temp->next;
        }
        if(n > count) {
            cout << "List is smaller than " << n << " elements.\n";
            return;
        }
        int move = count - n;
        temp = head;
        while(move--) {
            temp = temp->next;
        }
        cout << "The " << n << "th node from end is: " << temp->data << endl;
    }

    Node* reverseKgroup(Node* start, int k){
        Node* current = start;
        Node* prev = 0;
        Node* nextNode = 0;
        int cnt = 0;

        while(current != 0 && cnt < k){
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            cnt++;
        }

        if(nextNode != 0){
            start->next = reverseKgroup(nextNode, k);
        }

        return prev;
    }

    void reverseKnodes(int k){
        head = reverseKgroup(head, k);
    }

    void createLoop(){
        if(head == 0 || head->next == 0)
            return;
        Node* temp = head;
        while(temp->next != 0) {
            temp = temp->next;
        }
        temp->next = head->next;
    }

    void detectRemoveLoop(){
        Node* oneS = head;
        Node* twoS = head;

        while(twoS != 0 && twoS->next != 0){
            oneS = oneS->next;
            twoS = twoS->next->next;
            if (oneS == twoS) {
                break;
            }
        }

        if(oneS != twoS){
            cout<<"No loop found.\n";
            return;
        }

        oneS = head;
        Node* prev = 0;

        while(oneS != twoS){
            prev = twoS;
            oneS = oneS->next;
            twoS = twoS->next;
        }

        prev->next = 0;
        cout<<"Loop detected and removed."<<endl;
    }
};

int main() {
    LinkedList a;

    a.addEnd(10);
    a.addEnd(20);
    a.addEnd(30);
    a.addStart(5);
    a.addPosition(15, 3);

    cout<<"The linked list is:"<<endl;
    a.printList();

    a.printNthfromEnd(2);

    a.createLoop();
    a.detectRemoveLoop();

    cout<<"List after removing loop:"<<endl;
    a.printList();

    a.reverseKnodes(2);
    cout<<"List after reversing in groups of 2:"<<endl;
    a.printList();

    return 0;
}
