// Author : ysh
// 10/22/2022 Sat 13:13:51.77
// https://www.luogu.com.cn/problem/P1129
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<bool>mark;
vector<int>now;
bool check(int x,vector<vector<int>>&f) {
    // debug(x);
    for(int &i : f.at(x)) {
        // debug(x);
        if(mark.at(i)) continue;
        mark.at(i) = 1;
        if(now.at(i) != -1) {
            if(!check(now.at(i),f)) {
                continue;
            }
        }
        now.at(i) = x;
        return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        // assert(m != 1);
        now = vector<int>(m,-1);
        vector<vector<int>>f(m),g(m);
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<m;j++) {
                // char now = getchar();
                // while(now != '0' && now != '1') now = getchar();
                char now;cin>>now;
                if(now == '1') {
                    f.at(i).push_back(j);
                    g.at(j).push_back(i);
                    // cerr<<i<<" "<<j<<"\n";
                }
            }
        }
        // debug(f);
        // debug(f[1]);
        int ans = 0;
        for(int i = 0;i<m;i++) {
            mark = vector<bool>(m);
            if(check(i,f)) {
                ans++;
            }
            // debug(ans,now);
            // debug(ans);
        }
        bool c = 1;
        for(int &i : now) {
            if(i == -1) {
                c = 0;
                break;
            }
        }
        cout<<((c) ? "Yes" : "No")<<"\n";
    }
    return 0;
}