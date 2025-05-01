#include <iostream>

using namespace std;

template <typename T>

class stack{

 public:

     stack(int size){
        stackarray = new T[size];
        head = 0;
     }

     stack(const stack &s){

        head = s.head;
        stackarray = new T[s.head];

        for(int i=0; i<s.head; i++)
            stackarray[i] = s.stackarray[i];
     }

     ~stack(){

        delete [] stackarray;

     }

     const stack & operator = (const stack &s){
        delete stackarray;

        head = s.head;
        stackarray = new T[head];
        for(int i=0; i<head; i++){
            stackarray[i] = s.stackarray[i];
        }

        return *this;
     }

     bool empty(){
        if(head == 0)
            return true;
        return false;

     }
     void push(int x){
        stackarray[head] = x;
        head++;
     }

     T pop(){
        head--;
        return stackarray[head];
     }

     int size(){
        return head;
     }

     friend ostream & operator <<(ostream &out , const stack &s){
         out<<'[';
            if(s.head>0){
                out<<s.stackarray[0];
                for(int i=1; i<s.head; i++)
                    out <<", "<< s.stackarray[i];
            }
            out<<']';
            return out;
     }

 private:
    T * stackarray;
    int head;

};

int main(){

    stack <int> a(5);
    a.push(1);
    a.push(7);
    a.push(3);
    a.push(0);

    stack <int> b(a);

    cout << a.pop();



    cout << a;
}
