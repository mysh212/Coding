// Author : ysh
// 2023/09/23 Sat 15:44:33
// https://codeforces.com/problemset/problem/8/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x,y;cin>>x>>y;
    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i].first>>f[i].second;
    }

    function<int(int,int)> dt = [&] (int l,int r) {
        return abs(x - f[l].first) * abs(x - f[l].first) + abs(y - f[l].second) * abs(y - f[l].second) + abs(f[r].first - f[l].first) * abs(f[r].first - f[l].first) + abs(f[r].second - f[l].second) * abs(f[r].second - f[l].second) + abs(x - f[r].first) * abs(x - f[r].first) + abs(y - f[r].second) * abs(y - f[r].second);
    };

    int ans = 0;
    vector<int>mark(1 << n,-1);
    function<int(int,int,int)> check = [&] (int x,int mask,int now) {
        if(mask == (1 << n) - 1) return now;
        if(mark.at(mask) != -1) return mark.at(mask);
        while(mask & (1 << x)) x++;
        int ans = INT_MAX;
        for(int i = x + 1;i<n;i++) {
            if(mask & (1 << i)) continue;
            ans = min(ans,check(x + 1,mask | (1 << x) | (1 << i),now + dt(x,i)));
        }
        if(ans == INT_MAX) ans = dt(x,x);
        return mark.at(mask) = ans;
    };

    cout<<check(0,0,0);
    return 0;
}