// Author : ysh
// 05/29/2022 Sun 19:59:22.00
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    map<string,int>m;
    cin>>a;
    string last;
    bool c = 0;
    string llast = "";
    int lll = 0;
    for(int i = 0,len = a.size();i<len;i++) {
        string now = a.substr(i,1);
        if(!isdigit(now.at(0)) && lll != 0) {
            m[llast] += lll;
            lll = 0;
            c = 0;
        }
        if(now <= "Z" && now >= "A" && (!c)) {
            c = 1;
            llast = now;
            last = now;
            continue;
        }
        if(now <= "Z" && now >= "A" && (c)) {
            c = 1;
            m[llast]++;
            last = now;
            llast = now;
            continue;
        }
        if(now <= "z" && now >= "a" && c) {
            llast = llast + now;
        }
        if(now <= "9" && now >= "0") {
            last = llast;
            llast = "";
        }
        if(now[0] <= '9' && now[0] >= '0') {
            lll = lll * 10 + stoi(now);
            continue;
        }
        // m[now]++;
        last = now;
    }
    if(c) m[llast]++;
    for(auto i : m) {
        cout<<i.first<<" "<<i.second<<"\n";
    }
    return 0;
}