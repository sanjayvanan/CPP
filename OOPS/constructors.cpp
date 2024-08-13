#include<iostream>
using namespace std;

class Students{
    public:

        string name = "sanjayvanan";
        int age = 21;
        Students(){ //default constructor
            cout<<" from the constructor";
        }
};

class Teachers{

    int names,age;
    public:
        Teachers(string name, int age){ //parametrized constructor
            cout<<"\nthis is "<<name<<" his age is "<<age;
        }
        Teachers(Teachers& Val){ //copy constructor
            names = Val.names;
            age = Val.age;
            cout<< "\n copy constructor called";

        }

};

int main(){
    Students S;
    Teachers T("Kumar", 40);
    Teachers T1("Ajay", 42);
    Teachers Ajay(T);
    return 0;
}