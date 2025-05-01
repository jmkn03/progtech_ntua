#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int> > adj;
vector <bool> visited;


class Graph{

    int no;

public:

    Graph(int x){
        this->no = x;
        adj.assign(no,vector<int>());
        visited.assign(no,false);
    }


    void addEdge(int x, int v){
        adj[x].push_back(v);
    }

    void DFS(int s){
        cout << s << " ";
        visited.at(s)=true;

        for(int i=0; i<adj.at(s).size(); i++){
            int v=adj.at(s).at(i);
            if(!visited.at(v)){
                visited.at(v)=true;
                DFS(v);
            }
        }
    }


    void BFS(int s){

        visited.assign(no,false);
        queue<int> q;
        q.push(s);
        visited.at(s) = 1;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            cout << n << " ";

            for(int i=0; i<adj.at(n).size(); i++){
                if(visited.at(adj.at(n).at(i)) == false){
                    visited.at(adj.at(n).at(i)) = true;
                    q.push(adj.at(n).at(i));
                }
            }
        }
    }
};

int main()
{
    Graph g(13);

    int V, E, a, b, s;
    cin >> V >> E >> s;

    for (int i=0; i<E; i++){
       cin >> a >> b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }

    g.DFS(s);

    cout << endl << endl;

    g.BFS(s);

    return 0;
}
