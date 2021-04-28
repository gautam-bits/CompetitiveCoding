#include <iostream>
#include <string.h>

using namespace std;

class Human {
private:
    int age;

public:

    string name = "dd";
    void display() ;

    void getAge() {
        cout<<age<<endl;
    }

    
};

void Human:: display() {
    string s = "Hello";
    cout<<s<<" "<<Human::name<<endl;
}

int main () {

    Human gb;
    Human* to = new Human();

    gb.display();

    to->name = "no";
    to->display();
}