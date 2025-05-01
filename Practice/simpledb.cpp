#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<string,string> p;
p full_name;
typedef tuple<int,p,int,int> db;


bool idsortasc(const db& db1, const db& db2){
    return get<0>(db1) < get<0>(db2);
}
bool idsortdesc(const db& db1, const db& db2){
    return get<0>(db1) > get<0>(db2);
}
bool namesortasc(const db& db1, const db& db2){
    if(get<1>(db1).second == get<1>(db2).second)
        return get<1>(db1).first < get<1>(db2).first;
    return get<1>(db1).second < get<1>(db2).second;
}
bool namesortdesc(const db& db1, const db& db2){
    if(get<1>(db1).second == get<1>(db2).second)
        return get<1>(db1).first > get<1>(db2).first;
    return get<1>(db1).second > get<1>(db2).second;
}
bool yearsortasc(const db& db1, const db& db2){
    return get<2>(db1) < get<2>(db2);
}
bool yearsortdesc(const db& db1, const db& db2){
    return get<2>(db1) > get<2>(db2);
}
bool salarysortasc(const db& db1, const db& db2){
    return get<3>(db1) < get<3>(db2);
}
bool salarysortdesc(const db& db1, const db& db2){
    return get<3>(db1) > get<3>(db2);
}



int main(){


    vector<db> V;

    int N;
    cin >> N;
    string name,surname;

    for(int i=0; i<N; i++){
        db entry;
        cin >> get<0>(entry);

        cin >> name >> surname;

        full_name = make_pair(name,surname);
        get<1>(entry) = full_name;

        cin >> get<2>(entry);
        cin >> get<3>(entry);
        V.push_back(entry);
    }

//    for(auto it : V){
//        cout << get<0>(it) << endl;
//        cout << get<1>(it).first << ' ' << get<1>(it).second << endl;
//        cout << get<2>(it) << endl;
//        cout << get<3>(it) << endl;
//    }
//    cout << endl;





    int M,item;
    string what,order;
    cin >> M;

    for(int i=0; i<M; i++){
        sort((V.begin()), V.end(),idsortasc);
        cin >> what >> order >> item;

        if(what == "id"){
            if(order == "desc"){
                sort(V.begin(),V.end(),idsortdesc);
            }
        }
        else if(what == "name"){
            if(order == "asc")
                sort(V.begin(),V.end(),namesortasc);
            else
                sort(V.begin(),V.end(),namesortdesc);
        }
        else if(what == "year"){
            if(order == "asc")
                sort(V.begin(),V.end(),yearsortasc);
            else
                sort(V.begin(),V.end(),yearsortdesc);
        }
        else{
            if(order == "asc")
                sort(V.begin(),V.end(),salarysortasc);
            else
                sort(V.begin(),V.end(),salarysortdesc);
        }
        cout << "Query: " << what << ' ' << order << ' ' << item << endl;
        int j=0;
        for(auto it:V){
            if(j<item){
                j++;
                cout << get<0>(it) << ' ';
                cout << get<1>(it).first << ' ' << get<1>(it).second << ' ';
                cout << get<2>(it) << ' ';
                cout << get<3>(it);
                cout << endl;
            }
        }
    }

}
