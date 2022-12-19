// Author : ysh
// 12/16/2022 Fri 20:48:59.59
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    int d,e,f;cin>>d>>e>>f;
    if(a * e == d * b) {
        if(b * f == c * e) {
            cout<<"Too many";
            return 0;
        }
        cout<<"No answer";
        return 0;
    }
    cout<<"x="<<fixed<<setprecision(2)<<((c * e - b * f) * 1.0) / (a * e - b * d)<<"\n";
    cout<<"y="<<((d * c - a * f) * 1.0) / (b * d - a * e)<<"\n";
    return 0;
}