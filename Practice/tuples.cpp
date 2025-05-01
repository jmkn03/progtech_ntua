#include <iostream>
#include <tuple>
#include <string>

using namespace std;


int main(){

    typedef tuple<string,string,int> Data;

    Data T1;
    Data T2("Demetris","Markides",19);

    T1 = make_tuple("Vasilis","Ioannou",19);

    cout << get<0>(T2) << " " << get<1>(T2) << " " << get<2>(T2);
    cout << endl;
    cout << get<0>(T1) << " " << get<1>(T1) << " " << get<2> (T1);
    cout << endl;


}
