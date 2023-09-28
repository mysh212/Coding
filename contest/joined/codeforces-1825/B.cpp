// Author : ysh
// 05/08/2023 Mon 20:18:24.27
#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int n,int m,int a,int b,int c) {
    // small -> n - 1
    // self -> 1
    // greater -> n * (m - 1)
    if(n > m) swap(n,m);
    if(abs(a - c) < abs(b - c)) swap(a,b);
    return abs(b - c) * (n - 1) + 0 + abs(a - c) * (n * (m - 1));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n,m;cin>>n>>m;
        vector<int>f(n * m);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());
        int a = f.at(0),b = f.at(1),c = f.at(n * m - 2),d = f.at(n * m - 1);
        cout<<max(check(n,m,a,b,d),check(n,m,c,d,a))<<"\n";
    }
    return 0;
}