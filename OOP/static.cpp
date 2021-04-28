#include <iostream>
#include <string.h>

using namespace std;


class Human {
public:
    // static variable are declared once in heap and are shared amongst all the class instances
    // you cannot initialzie a static member of a class while defining it (note this can be done in functions tho)
    static int no_of_humans;

    Human(){
        no_of_humans++;
    }

    void total() {
        cout<<"Count :"<<no_of_humans<<endl;
    }

    //static methods are shared by every instance and these methods can only use static variables and are called
    // using the state defining operator ::

    static int getHumans() {
        return no_of_humans;
    }


};

int Human::no_of_humans = 0;

int main() {
    Human a1;
    a1.total();
    Human a2;
    a2.total();
    Human a3;
    a3.total();
    Human a4;
    a4.total();
    a1.total();
    a2.total();

    cout<<Human::getHumans()<<endl;

}