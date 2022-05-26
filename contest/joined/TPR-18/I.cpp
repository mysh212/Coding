// Author : ysh
// 04/17/2022 Sun 15:52:16.90
// TLE
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f(a);
    int c,d,e;
    for(int i = 0;i<a;i++) {
        cin>>c>>d>>d>>e;
        f[i] = {c,d};
    }
    sort(f.begin(),f.end());
    for(int i = 0;i<b;i++) {
        cin>>e;
        int ans = 0;
        for(int j = 0;j<a;j++) {
            if(f[j].first <= e&&f[j].second >= e) ans++;
            if(f[i].first > e) break;
        }
        cout<<ans<<" \n"[i == b - 1];
    }
}