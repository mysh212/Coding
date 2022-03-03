#include<bits/stdc++.h>
using namespace std;
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int n,k;cin>>n>>k;
    vector<pair<int,int>>f(n+2);
    vector<pair<int,int>>d(n+2);
    f[0] = {0,k+1};
    f[n+1] = {k,k+1};
    int tmp = 0;
    for(int i = 1;i<=n;i++) {
        cin>>tmp;
        f[i] = {tmp,0};
        d[i].first = i-1;
        d[i-1].second = i;
    }
    d[n].second = n+1;
    for(int i = 1;i<=n;i++) {
        cin>>tmp;
        f[i] = {f[i].first,tmp};
    }
    int c = 0;
    int ans = 0;
    int kk = f.size();
    bool m = 0;
    for(int i = 1;i<n+1;) {
        if(m == 1) {
            i = d[i].second;
            if(i == n+1) break;
        } else {
            m = 1;
        }
        if(f[d[i].first].first <= f[i].first - f[i].second||f[d[i].second].first >= f[i].first + f[i].second) {
            ans = max(ans,f[i].second);
            c++;
            d[d[i].first].second = d[i].second;
            d[d[i].second].first = d[i].first;
            i = d[i].first;
            m = 0;
        }
    }
    cout<<c<<"\n"<<ans;
    return 0;
}
