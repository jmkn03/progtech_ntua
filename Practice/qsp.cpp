#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

queue <int> q;
stack <int> s;

bool Q(){

    if(!q.empty()){
        int k=q.front();
        q.pop();
        s.push(k);
        return false;
    }
    return true;
}

bool S(){

    if(!s.empty()){
        int k=s.top();
        s.pop();
        q.push(k);
        return false;
    }
    return true;
}

void Print(){
    queue <int> pq = q;
    cout << pq.front();
    pq.pop();
    while(!pq.empty()){
        cout << ' ' << pq.front();
        pq.pop();
    }
    cout << endl;
}



int main(){

    int N;
    string str;

    cin >> N;
    for(int i=0; i<N; i++){
        int k;
        cin >> k;
        q.push(k);
    }

    bool b = false;
    cin >> str;
    int i=0;
    while(i<str.size() && !b){
        if(str[i] == 'Q')
            b=Q();
        else if (str[i] == 'S')
                b=S();
        else
            Print();

        i++;
    }
    if(b)
        cout << "error" << endl;

}
