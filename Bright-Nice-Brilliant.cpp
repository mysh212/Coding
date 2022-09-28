// Author : ysh
// 09/25/2022 Sun  8:26:41.13
// https://codeforces.com/contest/1734/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int n;cin>>n;
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j <= i;j++) {
                if(j == 1 || j == i) {
                    cout<<1<<" ";
                    continue;
                }
                cout<<"0 ";
            }
            cout<<"\n";
        }
    }
    return 0;
}