#include<iostream>
#include<utility>


using namespace std;

typedef pair<int,int> Node;

int main(){
    int N,M,c=0;
    int Path[2];
    cin>>N>>M;
    Node Ar[M];
    int NodeValue[N];

    for(int i=0;i<N;i++)
        NodeValue[i]=0;

    for(int i=0;i<M;i++){
        cin>>Ar[i].first>>Ar[i].second;
        NodeValue[Ar[i].first]++;
        NodeValue[Ar[i].second]++;
    }
    int OddCounter=0;
    for(int i=0;i<N;i++){
        if(NodeValue[i]%2!=0){
            //if 2 vertices are odd then there is an Euler path
            OddCounter++;
            if(c<2) Path[c++] = i;
        }
    }
    if(OddCounter==0)
        cout<<"CYCLE"<<endl;
    else if(OddCounter==2)
        cout<<"PATH "<<Path[0]<<' '<<Path[1]<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;

    return 0;
}
