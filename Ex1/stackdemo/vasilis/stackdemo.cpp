#include<iostream>


using namespace std;

template <typename T>
class stack{
public:
    stack<T>(int size);
    stack<T> (const stack &s);
    ~stack();
    const stack& operator= (const stack &s){
        node *current = Head,*Next;
        Head = s.Head;
        while(current != NULL){
            Next = current -> next;
            delete current;
            node *current = Next;
        }
        delete current;

        return *this;
    }

    bool empty();
    void push (const T &x);
    T pop();
    int size();
    int GetHead(){
        return Head;
    }

    friend ostream& operator<< (std::ostream &out, const stack &s) {
        node *ptr,*Last;
        if(s.Head==NULL){
            out<<"[]";
            return out;
        }

        T Array[s.MaxPos];
        int i=1;

        ptr = s.Head;

        out << '[';
        Array[0]=ptr->data;
        ptr = ptr->next;

        while(ptr != NULL){
            Array[i] = ptr->data;
            i++;
            ptr = ptr->next;
        }
        out<<Array[s.MaxPos-1];
        for(int i=s.MaxPos-2;i>=0;i--)
            out<<", "<<Array[i];
        out<<']';
        return out;
    }

private:
    int Listsize;
    int MaxPos;
    struct node{
        T data;
        node* next;
    };
    node *Head;
};

template <typename T> stack<T>::stack(int size){

    node *Head = new node;
    Head = NULL;
    MaxPos=0;
    Listsize=size;
}
template <typename T> stack<T>::stack(const stack &s){

    node *Head = new node;
    Head = s.Head;
    MaxPos =s.MaxPos;
    Listsize = s.Listsize;
}

template <typename T> stack<T>::~stack(){

    delete Head;
    Head = NULL;

}

template <typename T> bool stack<T>::empty(){
    if(Head==NULL) return true;
    return false;
}
template<typename T> void  stack<T>::push(const T &x){
    node* ptr= new node;
    ptr->data=x;
    ptr->next=Head;
    Head = ptr;
    MaxPos++;
}

template<typename T> T stack<T>:: pop(){
    if(Head!=NULL){
        node *ptr = Head;
        T value = ptr->data;
        Head = Head->next;
        delete ptr;
        MaxPos--;
        return value;
    }
}
template<typename T> int stack<T>::size(){
    return MaxPos;
}

int main(){

    stack <int> s(5);
    //s.push(45);
    //s.push(23);
    //cout << s.pop() << endl;
    cout << s;

}




