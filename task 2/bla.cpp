#include <iostream>
#include <cmath>  // For M_PI constant
using namespace std;

class Circle{
private:
    float radius;
public:
    Circle(float r){
        radius = r;
    }

    friend void compareTwoCircles(Circle area1, Circle area2);
};

void compareTwoCircles(Circle area1, Circle area2){
    float circle1 = M_PI * area1.radius * area1.radius;
    float circle2 = M_PI * area2.radius * area2.radius;

    if(circle1 > circle2){
        cout << "Circle 1's area is larger than Circle 2" << endl;
    }
    else if(circle1 < circle2){
        cout << "Circle 2's area is larger than Circle 1" << endl;
    }
    else{
        cout << "Both circles have equal area." << endl;
    }
}

int findMax(int num1, int num2){
    return (num1 > num2) ? num1 : num2;
}

float findMax(float num1, float num2){
    return (num1 > num2) ? num1 : num2;
}

int findMax(int num1, int num2, int num3){
    if (num1 >= num2 && num1 >= num3)
        return num1;
    else if (num2 >= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

float findMax(int num1, float num2){
    if(num1 > num2){
        return num1;
    }  
    else{
        return num2;
    }
}

int main(){
    Circle area1(6.3);
    Circle area2(8.9);

    compareTwoCircles(area1, area2);

    cout << "The maximum between 14 and 10 two is: " << findMax(14, 10) << endl;
    cout << "The maximum between 14.5 and 10.3 is: " << findMax(14.5f, 10.3f) << endl;
    cout << "The maximum between 12, 9 and 20 is: " << findMax(12, 9, 20) << endl;
    cout << "The maximum between 8 and 11.9 is: " << findMax(8, 11.9f) << endl;

    return 0;
}