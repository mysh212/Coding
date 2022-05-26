// Author : ysh
// 04/23/2022 Sat 18:12:44.78
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),v(a,INT_MAX);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
        int now;
        if(i - b - 1 >= 0) {
            v[i] = min(v[i],v[i - b - 1] + f[i]);
            now = v[i - b - 1] + f[i];
        } else {
            v[i] = min(v[i],f[i]);
            now = f[i];
        }
        for(int j = max(i - b,0);j<=min(i + b,a - 1);j++) {
            v[j] = min(v[j],now);
        }
            // for(int i : v) cout<<i<<" ";
            // cout<<"\n";
    }
    cout<<v[a - 1];
    return 0;
}