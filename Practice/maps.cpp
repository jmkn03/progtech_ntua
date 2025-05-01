#include <iostream>
#include <map>
#include <string>

using namespace std;

string ph[] = {"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee","Zulu"};

map<char,string> m_az;
map<string,char> m_ph;

void az_to_ph(string s){

    for(int i=0; i<s.size(); i++){
        while(s[i]==' ')
            i++;
        cout << m_az[s[i]] << " ";
    }
    cout << endl;
}

void ph_to_az(string s){

    cout << m_ph[s] << endl;
}


int main(){



    for(int i=0; i<26; i++){
        m_az[char('A' + i)] = ph[i];
        m_ph[ph[i]] = char('A' + i);
    }

    string st = "Charlie Zulu";
    ph_to_az(st);


    return 0;
}

