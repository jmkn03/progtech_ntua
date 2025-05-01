#include <iostream>
#include <vector>

using namespace std;

vector <int> v1;
vector <int> v2;

int main(){

    int N,c=0;
    string s;
    cin >> N;
    cin >> s;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '1'){
            if(i%2==0 || i==0){
                v1.push_back(1);
                cout << '1' << endl;
            }
            else{
                v2.push_back(1);
                cout << '2' << endl;
            }
        }
        else{
            if(c%2==0 || c==0){
                while(v1.size() != 1){
                    v1.pop_back();
                    v2.push_back(1);
                    cout << "1 2" << endl;
                }
                if(v1.size()==1){
                    cout << '1' << endl;
                    v1.pop_back();
                }
            }
            else{
                while(v2.size() != 1){
                    v2.pop_back();
                    v1.push_back(1);
                    cout << "2 1" << endl;
                }
                if(v2.size()==1){
                    cout << '2' << endl;
                    v2.pop_back();
                }
            }
            c++;
        }
    }
}
