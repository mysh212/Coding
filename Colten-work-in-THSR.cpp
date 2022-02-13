// Author : ysh
// 02/13/2022 Sun 16:03:37.98
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/I
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    int a[m] = {};
    for(int i = 0;i<m-1;i++) {
        cin>>a[i];
    }
    while(n--) {
        int b,c,d,e;cin>>b>>c>>d>>e;
        c = 4 - c;
        bool f[m] = {};
        while(e--) {
            int tmp;cin>>tmp;
            f[tmp-1] = 1;
        }
        cout<<b<<" ";
        int t = a[0];
        cout<<d<<" ";
        for(int i = 1;i<m;i++) {
            if(f[i] == 1)  {
                cout<<t/c + d<<" ";
                d = d + (c<<1);
            } else {
                cout<<"-- ";
            }
            t += a[i];
        }
        cout<<"\n";
    }
    return 0;
}