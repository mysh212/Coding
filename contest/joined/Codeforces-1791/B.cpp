// Author : ysh
// 02/03/2023 Fri 22:47:00.78
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int,pair<int,int>>r({{'U',{0,1}},{'D',{0,-1}},{'L',{-1,0}},{'R',{1,0}}});
    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        int x = 0,y = 0;
        bool c = 0;
        char t;
        while(m--) {
            cin>>t;
            // debug(x,y);
            x = x + r[t].first;
            y = y + r[t].second;
            if(x == 1 && y == 1) c = 1;
        }
        cout<<(c ? "YES\n" : "NO\n");
    }
    return 0;
}