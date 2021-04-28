#include <iostream>
#include <string.h>

using namespace std;

class Human {
private:
    string name;
    int age;
public:

    Human() {
        cout<<"constructor"<<endl;
        name = "default";
        age = 0;
    }

    Human(string iname) {
        name = iname;
        age = 0;
    }

    ~Human() {
        cout<<"destructor"<<endl;
    }

    string getName() {
        return name;
    }

    
};

class Human2 {
private:
    string* name;
    int* age;
public:

    Human2(string iname,int iage) {
        cout<<"constructor"<<endl;
        name = new string;
        age = new int;

        *name = iname;
        *age = iage;

    }


    ~Human2() {
        cout<<"destructor"<<endl;
        delete name;
        delete age;
    }

    string getDetails() {
        return *name + " " + to_string(*age) + "\n";
    }

    
};


int main () {

    Human2* gb = new Human2("yo",5);

    cout<<gb->getDetails();


    delete gb;
;

}
