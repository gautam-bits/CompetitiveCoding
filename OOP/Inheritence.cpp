#include<iostream>
#include<string.h>

using namespace std;

class Person {
protected:
    string secret;
public:
    string name;
    int age;

    void setName(string iname) {
        name = iname;
    }

    void setAge(int iage) {
        age = iage;
    }

    Person() {
        secret = "I love to code";
    }
};

//protrcted can also be inherited but not private

class Student : public Person {
public:
    int id;
    void setId(int iId) {
        id = iId;
    }

    void display()  {
        cout<<name<<" "<<age<<" "<<id<<" "<<secret<<endl;
    }
};


int main(int argc, char const *argv[])
{
    Student gautam ;

    gautam.setAge(5);
    gautam.setId(101);
    gautam.setName("Gautam");

    //cout<<gautam.secret; // cannot be accessed

    gautam.display();


    return 0;
}



