// Author : ysh
// 2024/01/02 Tue 16:44:38
// https://codeforces.com/contest/1916/problem/A
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;a = b = 0;
        int n,m ;cin>>n>>m;
        int ans = 1;
        bool c = 1;
        re(n) {
            int tmp;cin>>tmp;
            ans = ans * tmp;
            if(ans > 2023) ans = 0,c = 0;
        }
        if(!c) goto no;
        if(2023 % ans != 0) goto no;
        if(ans != 2023 && m == 0) goto no;

        yes:
        cout<<"YES\n";
        cout<<2023 / ans<<" ";
        re(m - 1) outs(1);
        cout<<"\n";
        continue;

        no:
        cout<<"NO\n";
    }
    return 0;
}