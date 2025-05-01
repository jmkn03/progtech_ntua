#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){

    stack<char>init;
    stack<char>s1;
    stack<char>s2;

    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++)
        cin >> A[i];

    string sinit,st1,st2;
    cin >> sinit >> st1 >> st2;

    for(int i=sinit.size()-1; i>=0; i--)
        init.push(sinit[i]);
    for(int i=st1.size()-1; i>=0; i--)
        s1.push(st1[i]);
    for(int i=st2.size()-1; i>=0; i--)
        s2.push(st2[i]);

    for(int i=N-1; i>=0; i--){
        if(A[i]==1){
            init.push(s1.top());
            s1.pop();
        }
        else{
            init.push(s2.top());
            s2.pop();
        }
    }

    while(!init.empty()){
        cout << init.top();
        init.pop();
    }
    cout << endl;
    while(!s1.empty()){
        cout << s1.top();
        s1.pop();
    }
    cout << endl;
    while(!s2.empty()){
        cout << s2.top();
        s2.pop();
    }
    cout << endl;



}
