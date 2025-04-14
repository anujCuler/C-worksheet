#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> names(5); 
map<string, int> ages;
int namesCount = 0; 

void addPerson(string name, int age){
    names[namesCount] = name; 
    namesCount++;           
    ages[name] = age;
}

void findAboveAge(int minAge){
    cout<<"People older than"<< minAge << ":"<<endl;
    for(int i = 0; i < namesCount; i++) {
        string name = names[i];
        if(ages[name] > minAge) {
            cout<<name<<" -"<<ages[name]<<" years old."<<endl;
        }
    }
}

void sortAndDisplayNames() {
    for(int i = 0; i < namesCount - 1; i++) {
        for(int j = 0; j < namesCount - i - 1; j++) {
            if(names[j] > names[j + 1]){
                string temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }


    cout<<"Names sorted alphabetically:\n";
    for(int i = 0; i<namesCount; i++){
        cout<<names[i]<<endl;
    }
}

int main() {
    addPerson("Anuj", 19);
    addPerson("Anubhaw", 20);
    addPerson("Aryan", 18);
    findAboveAge(17);
    cout<<endl;
    sortAndDisplayNames();
    return 0;
}
