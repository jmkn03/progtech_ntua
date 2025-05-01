#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int main(){

    typedef pair<string,int> psi;
    vector <psi> vcnt;

    typedef vector <string> vs;
    vector <vs> v;


    int N,D;
    cin >> N >> D;
    int d;
    string w;

    for(int i=0; i<N; i++){
        cin >> d >> w;

        vs::iterator it = find(v.at(d).begin(), v.at(d).end(),w);
        if(it == v.at(d).end()){
            v.at(d).push_back(w);
            vcnt.push_back(make_pair(w,1));
        }
        else{
            vector <psi>::iterator ipsi = find(vcnt.begin(),vcnt.end(),w);
                if(ipsi->first == w)
                    ipsi->second++;
        }
    }






}


