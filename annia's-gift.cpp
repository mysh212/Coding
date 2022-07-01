// Author : ysh
// 07/01/2022 Fri  6:32:05.52
// https://choj.me/problem/c002
#include<bits/stdc++.h>
using namespace std;
string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                  "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string,char>m;
    for(int i = 0;i<26;i++) {
        m.emplace(morse[i],(char) ((int) 'A' + i));
    }
    string a;getline(cin,a);
    string t;
    string last;
    t = last = "";
    bool c = 0;
    for(int i = 0,len = a.size();i<len;i++) {
        if(a.at(i) == '_') {
            if(!c) {
                t = t + m.find(last)->second;
                last = "";
                c = 1;
                continue;
            }
            t = t + ' ';
            c = 0;
            continue;
        }
        last = last + a.at(i);
        c = 0;
    }
    t = t + m.find(last)->second;
    cout<<t;
    return 0;
}