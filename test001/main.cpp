#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

bool cmp(pair<string, string> p1, pair<string, string> p2){
    return p1.second < p2.second;
}

int main(){
    freopen("test.in", "r", stdin);
    string str;
    map<int , int> m;
    map<string, int> m2;
    map<string, string> m3;
    m3["jt"] = "o";
    m3["ib"] = "n";
    m3["gv"] = "g";
    m3["ti"] = "r";
    m3["sm"] = "a";
    m3["sd"] = "t";
    m3["rw"] = "u";
    m3["zl"] = "l";
    m3["sh"] = "s";
    m3["lj"] = ".";
    m3["yn"] = "i";
    m3["ow"] = "h";
    m3["dd"] = "m";
    m3["dx"] = "e";
    m3["vi"] = "y";
    m3["lk"] = "c";
    m3["pd"] = "f";
    m3["eg"] = "d";
    m3["dn"] = "p";
    m3["ro"] = "j";
    m3["ca"] = "b";
    m3["ox"] = "k";
    m3["tb"] = "w";
    m3[""] = "";
    m3[""] = "";
    m3[""] = "";

    while(cin >> str){
        //cout << str.length() << endl;
        for(int i = 0;i < (int)str.length();i+=2){
            int tmp = (str[i]-'a')*26 + (str[i+1]-'a');
            tmp %= 256;
            //cout << tmp << endl;
            m[tmp]++;
            m2[str.substr(i, 2)]++;
            if(m3.count(str.substr(i, 2)))
                cout << m3[str.substr(i, 2)];
            else
                cout << " ";//cout << str.substr(i, 2);
            cout << " ";
        }
        puts("");
    }

    vector<pair<string, string>> v;
    for(auto it : m3){
        v.push_back(make_pair(it.first, it.second));
        //cout << it.first << " " << it.second << endl;
    }

    sort(v.begin(), v.end(), cmp);
    for(auto it : v){
        cout << it.first << " ";
        cout << (it.first[0]-'a') << " ";
        cout << (it.first[1]-'a') << " ";
        cout << " " << it.second << endl;
    }
    /*
    for(auto it : m2){
        cout << it.first << " " << (it.first[0]-'a')*(it.first[1]-'a') << " " << it.second << endl;
    }
    */

    return 0;
}
