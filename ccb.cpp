// Author : ysh
// 10/22/2022 Sat 13:13:51.77
// https://www.luogu.com.cn/problem/P1129
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#include<fast>
vector<vector<bool>>mark;
vector<int>now;
bool check(int x,vector<vector<int>>&f) {
    for(int &i : f.at(x)) {
        debug(x);
        if(mark.at(x).at(i)) continue;
        mark.at(x).at(i) = 1;
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

    int n = readint();
    while(n--) {
        int m = readint();
        assert(m != 1);
        mark = vector<vector<bool>>(m,vector<bool>(m));
        now = vector<int>(m,-1);
        vector<vector<int>>f(m);
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<m;j++) {
                char now = getchar();
                while(now != '0' && now != '1') now = getchar();
                if(now == '1') {
                    f.at(i).push_back(j);
                    // cerr<<i<<" "<<j<<"\n";
                }
            }
        }
        debug(f[1]);
        int ans = 0;
        for(int i = 0;i<m;i++) {
            if(check(i,f)) {
                ans++;
            }
        }
        cout<<(ans == m ? "Yes" : "No")<<"\n";
    }
    return 0;
}