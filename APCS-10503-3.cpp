// Author : ysh
// 04/29/2022 Fri 21:21:49.72
#include<bits/stdc++.h>
using namespace std;
struct box{
    int l = 0,r = 0;
};
inline bool cp(box a,box b) {
    return a.l<b.l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<box>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i].l>>f[i].r;
        if(f[i].l > f[i].r) swap(f[i].l,f[i].r);
    }
    sort(f.begin(),f.end(),cp);
    int ans = 0;
    int nowr = 0;
    // for(int i = 0;i<n;i++) {
    //     cout<<f[i].l<<" "<<f[i].r<<"\n";
    // }
    for(int i = 0;i<n;i++) {
        if(f[i].r <= nowr) continue;
        if(f[i].l >= nowr) {
            ans += f[i].r - f[i].l;
            nowr = f[i].r;
            // cout<<ans<<"\n";
            continue;
        }
        ans += f[i].r - nowr;
        // cout<<ans<<"\n";
        nowr = f[i].r;
    }
    cout<<ans;
    return 0;
}