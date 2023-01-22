// Author : ysh
// 09/16/2022 Fri 11:07:18.90
// https://atcoder.jp/contests/dp/tasks/dp_s
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
const int R = (int) (1e9 + 7);
int b;
inline int pos(int x) {
    while(x < 0) x = x + b;
    while(x >= b) x = x - b;
    return x;
}
vector<vector<int>>mark;
int check(int x,int r) {
    if(mark.at(x).at(r) != -1) return mark.at(x).at(r);
    debug(x,r);
    if(x == 1) {
        int ans = 0;
        for(int i = 0;i<=9;i++) {
            if(i % b == r) ans++;
        }
        return mark.at(x).at(r) = ans;
    }
    int ans = 0;
    for(int i = 0;i<=9;i++) {
        ans += check(x - 1,pos((r - i) % b));
    }
    return mark.at(x).at(r) = ans % R;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    cin>>b;
    vector<short>f;
    for(char i : a) {
        f.push_back(i - '1' + 1);
    }
    int n = f.size();
    mark.resize(n + 1,vector<int>(b,-1));
    // check(n,0);
    debug(mark);
    int ans = 0;
    int last = 0;
    for(int i = n - 1;i>=1;i--) {
        short &now = f.at(n - 1 - i);
        for(int j = 0;j<now;j++) {
            int tmp = check(i,pos((b - last - j) % b));
            debug(tmp);
            ans = ans + tmp;
            ans = ans % R;
        }
        last = last + now;
        last = last % b;
    }
    for(int i = 0;i<=f.at(n - 1);i++) {
        if(pos((i - last) % b) == 0) ans++;
    }
    cout<<(ans - 1) % R;
    return 0;
}