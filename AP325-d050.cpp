// Author : ysh
// 03/11/2022 Fri  7:44:40.26
#include<bits/stdc++.h>
using namespace std;
struct line {
    int l = 0,r = 0;
};
inline bool cp(line a,line b) {
    return a.l<b.l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    line l[n];
    int tmpa,tmpb;
    for(int i = 0;i<n;i++) {
        cin>>tmpa>>tmpb;
        l[i].l = tmpa;
        l[i].r = tmpb;
    }
    sort(l,l+n,cp);
    int ll,r;ll=r=0;
    int ans = 0;
    // for(auto i : l) {
    //     cout<<i.l<<" "<<i.r<<"\n";
    // }
    for(int i = 0;i<n;i++) {
        if(l[i].l > r) {
            ll = l[i].l;
            r = l[i].r;
            ans += r - ll;
            //cout<<ans<<"\n";
        } else {
            if(l[i].r > r) {
                ans += l[i].r - r;
                r = l[i].r;
                //cout<<ans<<"\n";
            }
        }
    }
    cout<<ans;
    return 0;
}