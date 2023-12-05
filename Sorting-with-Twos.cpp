// Author : ysh
// 2023/12/05 Tue 20:33:26
// https://codeforces.com/problemset/problem/1891/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) cin>>i;

        int l = 0,r = 1;
        while(r <= n) {
            if(!is_sorted(f.begin() + l,f.begin() + r)) goto no;
            l = l << 1;
            r = r << 1;
            if(l == 0) l = 1;
        }
        if(!is_sorted(f.begin() + l,f.end())) goto no;

        yes:
        cout<<"YES\n";
        continue;

        no:
        cout<<"NO\n";
    }
}