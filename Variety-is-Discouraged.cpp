// Author : ysh
// 2025/02/21 Fri 20:16:51
// https://codeforces.com/contest/2064/problem/B
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

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) cin>>i, i--;
// #define short int
        vector<short> mark(n);
        for(int &i : f) if(mark.at(i) < 2) mark.at(i)++;

        // debug(mark);

        int ans = 0;
        int now = 0;
        int l = 0;
        int t = 0;
        pair<int,int>aans;
        for(int &i : f) {
            if(mark.at(i) == 2) now = -1, l = t + 1;
            if(++now > ans) {
                ans = now;
                aans = {l,t};
            }
            // ans = max(ans, ++now);
            t++;
        }

        if(ans == 0) cout<<"0\n";
        else cout<<aans.first + 1<<" "<<aans.second + 1<<"\n";
        // cout<<ans<<" ";
    }
    return 0;
}