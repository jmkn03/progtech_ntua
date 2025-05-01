#include <iostream>


using namespace std;

template <typename T>

class stack {

    public:

        stack (int size) {

            sz=size;
            StackArray = new T[size];
            head = 0;
        }

        stack (const stack &s) {

            sz = s.sz;
            head = s.head;
            StackArray = new T[sz];

            for(int i=0;i<s.head;i++)
                StackArray[i] = s.StackArray[i];
        }

        ~stack () {
                delete[] StackArray;
        }

        const stack & operator = (const stack &s) {

            delete []StackArray;
            sz = s.sz;
            head = s.head;
            StackArray = new T[sz];

            for(int i=0;i<s.head;i++)
                StackArray[i] = s.StackArray[i];

            return *this;
        }

        bool empty () {

            return(head == 0);
        }

        void push (const T &x) {

            StackArray[head++] = x;
        }

        T pop () {

            return StackArray[--head];
        }

        int size () {

            return head;
        }

        friend ostream & operator << (ostream &out, const stack &s) {

            out<<'[';
            if(s.head>0){
                out<<s.StackArray[0];
                for(int i=1; i<s.head; i++)
                    out <<", "<< s.StackArray[i];
            }
            out<<']';
            return out;
        }

    private:

        T* StackArray;
        int sz;
        int head;

};

int main(){

    stack <int> a(5);
    a.push(1);
    a.push(7);
    a.push(3);
    a.push(0);

    stack<int> b(2);
    b=a;

    cout << a.pop();



    cout << a;
}

