// Author : ysh
// 06/27/2022 Mon  7:54:06.54
#include<bits/stdc++.h>
using namespace std;
void check(string x,int a) {
    int n = x.size();
    vector<int>f(n + 1);
    for(int i = 1;i<n;i++) {
        int p = f[i - 1];
        while(x.at(p) != x.at(i) && p > 0) p = f[p - 1];
        if(x[i] == x[p]) f[i] = p + 1;
        if(f[i] == a) {
            cout<<"Yes\npos: "<<i - ((a << 1))<<"\n";
            return;
        }
    }
    cout<<"No\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        string c,d;cin>>c>>d;
        check(d + " " + c,b);
    }
    return 0;
}