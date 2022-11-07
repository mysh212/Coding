// Author : ysh
// 11/05/2022 Sat 19:12:15.41
// https://tioj.ck.tp.edu.tw/problems/2276
#include<bits/stdc++.h>
using namespace std;
vector<int>mark(64);
int ans = 0;
int check(int now,int r,vector<vector<bool>>&f) {
    // cerr<<r;
    if(r == 7) return 1;
    if(mark.at(now) != 0) return mark.at(now);
    assert(now < 64);
    int ans = 0;
    for(int i = 0;i<6;i++) {
        if(!(f[i][r - 1]) && !(now & (1 << (r - 1)))) {
            ans += check(now | (1 << (r - 1)),r + 1,f);
        }
    }
    return mark.at(now) = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<bool>>f(6,vector<bool>(6));
    for(int i = 0;i<6;i++) {
        int a;cin>>a;
        while(a--) {
            int tmp;cin>>tmp;
            f[i][tmp - 1] = 1;
        }
    }
    cout<<check(0,1,f);
    return 0;
}