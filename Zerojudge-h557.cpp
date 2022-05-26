// Author : ysh
// 04/20/2022 Wed 14:52:22.12
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int dt(int x,int y,int xx,int yy) {
    return ((x - xx) * (x - xx)) + ((y - yy) * (y - yy));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int r = b * b;
    map<pair<int,int>,int>f;
    int c,d;
    for(int i = 0;i<a;i++) {
        cin>>c>>d;
        for(int i = -b;i<=b;i++) {
            for(int j = -b;j<=b;j++) {
                int x = c + i;
                int y = d + j;
                if(dt(x,y,c,d) <= r) {
                    // printf("dt(%d,%d,%d,%d) = %d\n",x,y,c,d,dt(x,y,c,d));
                    f[{x,y}]++;
                }
            }
        }
    }
    int ans = 0;
    for(auto i : f) {
        // printf("{%d,%d}\n",i.first.first,i.first.second);
        // ans++;
        if(i.second & 1) {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}