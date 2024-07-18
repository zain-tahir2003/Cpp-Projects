#include<iostream>
#include<string>

using namespace std;

struct student {
    string name = "ZAin";
    string regnum = "23-cs-115";
    int marks = 90;
    float percent = 90.5;
};

int main(){
    student std2;
    cout << "Name: " << std2.name << endl;
    cout << "Registeration Number: " << std2.regnum << endl;
    cout << "Marks: " << std2.marks << endl;
    cout << "Percentage: " << std2.percent << endl;

    return 0;
}
