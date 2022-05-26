// Author : ysh
// 04/17/2022 Sun 15:12:32.60
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int ans = 0;
    while(n--) {
        int l = 0;cin>>l;
        string aa = "";
        string tmp = "";
        vector<string>f(4);
        vector<int>ll(4);
        bitset<4>yes;
        yes.reset();
        int mmax =  INT_MIN;
        int mmin = INT_MAX;
        for(int i = 0;i<4;i++) {
            cin>>f[i];
            ll[i] = f[i].size();
            if(ll[i] >= l) yes.set(i);
            mmax = max(mmax,ll[i]);
            mmin = min(ll[i],mmin);
        }
        // for(int i : ll) cout<<i<<" ";
        // cout<<"\n";
        // cout<<yes.to_string();
        string aans = "";
        cin>>aans;
        if(yes.count() == 0) {
            aa = f[2];
            if(aans == aa) ans++;
            continue;
        }
        if(yes.count() == 4) {
            aa = f[0];
            // cout<<aa;
            if(aans == aa) ans++;
            continue;
        }
        if(yes.count() == 1) {
            aa = f[yes._Find_first()];
            // cout<<aa;
            if(aans == aa) ans++;
            continue;
        }
        if(yes.count() == 3) {
            yes.flip();
            aa = f[yes._Find_first()];
            //cout<<aa;
            if(aans == aa) ans++;
            continue;
        }
        if(mmax - mmin >= l) aa = f[1];
        else aa = f[3];
            //cout<<aa;
        if(aans == aa) ans++;
    }
    cout<<ans;
    return 0;
}