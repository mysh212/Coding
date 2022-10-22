// Author : ysh
// 10/03/2022 Mon 10:07:10.98
// https://codeforces.com/problemset/problem/632/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<string>f(n);
    for(string &i : f) {
        cin>>i;
    }
    sort(f.begin(),f.end(),[] (string a,string b) {
        return a + b < b + a;
        if(a == b) return true;
        int aa = a.size();
        int bb = b.size();
        if(a.size() == b.size()) for(int i = 0,len = min(aa,bb);i<len;i++) {
            int na = aa - i - 1;
            int nb = bb - i - 1;
            if(a.at(na) < b.at(nb)) return a < b;
            if(a.at(na) > b.at(nb)) return a > b;
        }
        return a.size() < b.size();
    });
    for(string i : f) {
        cout<<i;
    }
    return 0;
}