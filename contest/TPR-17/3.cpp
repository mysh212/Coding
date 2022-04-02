// Author : ysh
// 04/02/2022 Sat 14:33:52.85
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int mmin = INT_MAX,cc;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.begin(),f.end());
    for(int j = 1;j<=a;j++) {
        int c = 0,l = b,g = 0;
        for(int i = j - 1;i >= 0;i--) {
            g += f[i] * (l / f[i]);
            c += l / f[i];
            l = l % f[i];
        }
        if(l > 0) {
            c += 1;
            g += f[0];
        }
        if(g < mmin) {
            mmin = g;cc = c;
        }
        if(g == mmin) {
            cc = min(cc,c);
        }
        // cout<<g<<" "<<c<<"\n";
    }
    cout<<mmin<<" "<<cc;
    return 0;
}