// Author : ysh
// 2023/06/24 Sat 08:01:58
// https://cses.fi/problemset/task/1690
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
const int R = (int) 1e9 + 7;
vector<int>f[20];
int mark[20][1 << 20];
int a,b;
int check(int x,int now) {
    if(x == a - 1 && now + 1 == (1 << x)) return 1;
    if(~mark[x][now]) return mark[x][now];
    int ans = 0;
    int tmp = now | (1 << x);
    for(int &i : f[x]) {
        if(now & (1 << i)) continue;
        ans += check(i,tmp);
        ans = ans % R;
    }
    return mark[x][now] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    memset(mark, -1, sizeof mark);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        if(a == b) continue;
        f[a - 1].push_back(b - 1);
    }

    cout<<check(0,0);
    return 0;
}