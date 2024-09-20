// Author : ysh
// 2024/09/18 Wed 21:56:16
// https://judge.citrc.tw/contest/22/problem/2-6
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    set<string>s;
    while(n--) {
        string a,b;cin>>a>>b;
        if(s.find(a) == s.end()) {
            cout<<"welcome, "<<b<<"\n";
            s.insert(a);
        } else {
            cout<<"sorry, email "<<a<<" has been used\n";
        }
    }
    return 0;
}