#include <iostream>
using namespace std;

class Father{
 public:
    Father(){
        age = 30;
    }
    ~Father();

    ostream& operator +(ostream );

    return_age(){
        return age;
    }


    ostream& operator <<(ostream &out){

        cout << "Hey" << endl;

        return out;
    }
 private:
    int age;
};

class Child:public Father{
 public:

     Child(){
        age = 1;
     }
     ~Child();
     int return__child_age(){
        return age;
     }
     int return_father_age(){
        return return_age();
     }


 private:
     int age;
};

int main(){

    Father f1;
    Child ch1;

    cout << ch1.return_age() + ch1.return_father_age();











}
