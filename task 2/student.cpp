#include <iostream>
using namespace std;
class Student{
    string name;
    public:
    float sub1, sub2, sub3, total, avg, percentage;

    void getData(){
        cout<<"Enter the name of the student : ";
        cin>>name;
        while(true){
        cout<<"Enter the marks for the three subjects of your choice: "<<endl;
        cin>>sub1>>sub2>>sub3;
        if (sub1 < 0 || sub1 > 100 || sub2 < 0 || sub2 > 100 || sub3 < 0 || sub3 > 100) {
            cout << "Error: Marks must be between 0 and 100! Please re-enter the marks." << endl;
        } 
        else {
            break; 
        }
     }
    }
        

    void totalmarks(){
            total = sub1+sub2+sub3;
        }
    

    void average(){
        avg = total / 3;
    }

    void totalTopercentage(){
        percentage = (total/300)*100;
    }

    void grade(){
        if(percentage >= 90){
            cout<<"Grade: A"<<endl;
        }
        else if(percentage >= 80){
            cout<<"Grade: B"<<endl;
        }
        else if(percentage >= 70){
            cout<<"Grade: C"<<endl;
        }
        else if(percentage >= 60){
            cout<<"Grade: D"<<endl;
        }
        else{
            cout<<"Grade: F"<<endl;
        }  
    }

    void Display(){
        cout<<"***Student Grading System***"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Total marks: "<<total<<endl;
        cout<<"Average: "<<avg<<endl;
        grade();
    }
};

    int main(){
        Student s;
        s.getData();
        s.totalmarks();
        s.average();
        s.totalTopercentage();
        s.Display();
    
    return 0;

    
}