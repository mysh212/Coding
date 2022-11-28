// Author : ysh
// 11/28/2022 Mon 21:23:36.93
// https://codeforces.com/problemset/problem/1742/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        set<int>s;
        bool c = 0;
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            if(s.find(tmp) != s.end()) c = 1;
            if(c) continue;
            s.insert(tmp);
        }
        cout<<(c ? "NO\n" : "YES\n");
    }
    return 0;
}