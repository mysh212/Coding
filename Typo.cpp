// Author : ysh
// 06/06/2022 Mon 18:52:56.82
// https://192.168.193.20/contest/2/problem/01
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    getline(cin,a);
    getline(cin,b);
    if(a.size() != b.size()) {
        cout<<"No";
        return 0;
    }
    if(a == b) {
        cout<<"Yes";
        return 0;
    }
    for(int i = 0,len = a.size();i<len;i++) {
        if(a[i] != b[i]) {
            string tmpa = a.substr(i + 2);
            string tmpb = b.substr(i + 2);
            debug(tmpa,tmpb);
            if(tmpa == tmpb) {
                cout<<"Yes";
                return 0;
            }
            cout<<"No";
            return 0;
        }
    }
}